/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebView
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WebView)
    {
        if (WebView->objectName().isEmpty())
            WebView->setObjectName(QString::fromUtf8("WebView"));
        WebView->resize(400, 300);
        WebView->setWindowTitle(QString::fromUtf8("WebView"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/VitKor/Downloads/web_v.ico"), QSize(), QIcon::Normal, QIcon::Off);
        WebView->setWindowIcon(icon);
        centralWidget = new QWidget(WebView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        WebView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WebView);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        WebView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WebView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WebView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WebView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WebView->setStatusBar(statusBar);

        retranslateUi(WebView);

        QMetaObject::connectSlotsByName(WebView);
    } // setupUi

    void retranslateUi(QMainWindow *WebView)
    {
        Q_UNUSED(WebView);
    } // retranslateUi

};

namespace Ui {
    class WebView: public Ui_WebView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
