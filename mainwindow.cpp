#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    closeurl(nullptr), openurl(nullptr), webview(nullptr), callback(nullptr), ui(new Ui::WebView)
{
    ui->setupUi(this);

    auto axWidget = new QAxWidget(ui->centralWidget);
    webview = axWidget;

    axWidget->setControl(QString::fromUtf8("{8856f961-340a-11d0-a96b-00c04fd705a2}"));
    axWidget->setObjectName(QString::fromUtf8("axWidget"));
    axWidget->setProperty("RegisterAsBrowser", QVariant(true));
    ui->verticalLayout ->addWidget(axWidget);

    QObject::connect(axWidget, SIGNAL(NavigateComplete(QString)), this, SLOT(onNavigatedTo(QString)));
    QObject::connect(axWidget, SIGNAL(NavigateError(IDispatch*,QVariant&,QVariant&,QVariant&,bool&)), this, SLOT(onNavigatedError()));
    QObject::connect(axWidget, SIGNAL(DocumentComplete(IDispatch*,QVariant&)), this, SLOT(onDocumentComplete()));

}

void MainWindow::onNavigatedTo(const QString& txt){
    if(needsClearCookies){
        closeOnDocumentComplete = true;
        auto urlToOpen = QString("javascript:void(("
                                 "function(){var a,b,c,e,f;f=0;a=document.cookie.split('; ');"
                                 "for(e=0;e<a.length&&a[e];e++)"
                                 "{f++;for(b='.'+location.host;b;b=b.replace(/^(?:%5C.|[^%5C.]+)/,''))"
                                 "{for(c=location.pathname;c;c=c.replace(/.$/,''))"
                                 "{document.cookie=(a[e]+'; domain='+b+'; path='+c+'; "
                                 "expires='+new Date((new Date()).getTime()-1e11).toGMTString());}}}})())");

         webview->dynamicCall("Navigate(const QString&)", urlToOpen);
         needsClearCookies = false;
    }

    if(closeurl !=nullptr && txt.startsWith(closeurl)){
        if(callback != nullptr){
          finished = true;
          callback(txt.toUtf8());
        }
    }
}

void MainWindow::onDocumentComplete(){
    if(closeOnDocumentComplete){
        this->close();
    }
}

void MainWindow::onNavigatedError(){
    qInfo("Navigate Error");
    if(callback != nullptr){
      callback("https://oauth.vk.com/error?network_error=1");
    }
}

void MainWindow::navigateToOpenUrl() {
	if (openurl != nullptr) {
		auto urlToOpen = QString(openurl);
		webview->dynamicCall("Navigate(const QString&)", urlToOpen);
	}
}

void MainWindow::clearCookes(const QString& url) {
    needsClearCookies = true;
    webview->dynamicCall("Navigate(const QString&)", url);
}


void MainWindow::closeEvent(QCloseEvent *event){
    if(callback != nullptr && !finished){
      callback("https://oauth.vk.com/error?cancel=1");
    }
    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
