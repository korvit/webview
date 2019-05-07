#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "global_helper.h"
#include <QAxWidget>
namespace Ui {
class WebView;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    const char* closeurl;
    const char* openurl;

    bool closeOnDocumentComplete = false;
    bool needsClearCookies = false;
    bool finished = false;

    QAxWidget* webview;
    UnityCallback callback;

    void closeEvent(QCloseEvent *event) override;
    void clearCookes(const QString& url);
    void navigateToOpenUrl();

public slots:
    void onNavigatedTo(const QString& txt);
    void onDocumentComplete();
    void onNavigatedError();

private:
    Ui::WebView *ui;
};

#endif // MAINWINDOW_H
