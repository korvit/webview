#include "mainwindow.h"
#include <QApplication>
#include "global_helper.h"

static MainWindow* mainwndw;

//for testing to run as an app
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.openurl = "https://oauth.vk.com/authorize?"
                "client_id=4473713&"
                "scope=notify,friends,photos,wall,groups,messages,notifications,offline,email&"
                "redirect_uri=https://oauth.vk.com/blank.html&"
                "display=popup&v=5.29&"
                "response_type=token";
    w.closeurl = "https://oauth.vk.com/blank.html";
    w.show();
    w.navigateToOpenUrl();
	//w.clearCookes(w.openurl);
    return a.exec();
}

//from dll
int dll_main(int argc, char *argv[],UnityCallback _callback,  const char* _openurl, const char* _closeurl)
{
    QApplication a(argc, argv);
	a.setQuitOnLastWindowClosed(true);

    MainWindow w;

    w.setWindowIcon(QIcon("web_v.ico"));
    w.setWindowTitle("WebView");
    w.resize(650,720);
    w.show();

    w.callback = _callback;
    w.closeurl = _closeurl;
    w.openurl = _openurl;

    w.navigateToOpenUrl();

    mainwndw = &w;

    return a.exec();
}

extern "C"{
    Q_DECL_EXPORT int OpenWebViewNative(const char* exepath, UnityCallback _callback, const char* _openurl, const char* _closeurl ) {
        int argc = 1;
        char* argv[1];
        argv[0] = const_cast<char*>(exepath);
        return dll_main(argc,argv,_callback, _openurl, _closeurl);
    }

	Q_DECL_EXPORT void quitWebView() {
		mainwndw->close();
	}

    Q_DECL_EXPORT int LogoutFrom(const char* exepath, const char* url) {
        int argc = 1;
        char* argv[1];
        argv[0] = const_cast<char*>(exepath);

        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        w.clearCookes(url);

        return a.exec();
    }
}
