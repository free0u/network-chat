/********************************************************************************
** Form generated from reading UI file 'debugger_for_chat.ui'
**
** Created: Sat 8. Dec 00:49:22 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGGER_FOR_CHAT_H
#define UI_DEBUGGER_FOR_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Debugger_for_chatClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonSend;
    QTextBrowser *textBrowserChat;
    QLineEdit *lineEditChat;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Debugger_for_chatClass)
    {
        if (Debugger_for_chatClass->objectName().isEmpty())
            Debugger_for_chatClass->setObjectName(QString::fromUtf8("Debugger_for_chatClass"));
        Debugger_for_chatClass->resize(600, 400);
        centralWidget = new QWidget(Debugger_for_chatClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonSend = new QPushButton(centralWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(250, 30, 75, 23));
        textBrowserChat = new QTextBrowser(centralWidget);
        textBrowserChat->setObjectName(QString::fromUtf8("textBrowserChat"));
        textBrowserChat->setGeometry(QRect(30, 110, 321, 41));
        lineEditChat = new QLineEdit(centralWidget);
        lineEditChat->setObjectName(QString::fromUtf8("lineEditChat"));
        lineEditChat->setGeometry(QRect(30, 30, 211, 21));
        Debugger_for_chatClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Debugger_for_chatClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Debugger_for_chatClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Debugger_for_chatClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Debugger_for_chatClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Debugger_for_chatClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Debugger_for_chatClass->setStatusBar(statusBar);

        retranslateUi(Debugger_for_chatClass);

        QMetaObject::connectSlotsByName(Debugger_for_chatClass);
    } // setupUi

    void retranslateUi(QMainWindow *Debugger_for_chatClass)
    {
        Debugger_for_chatClass->setWindowTitle(QApplication::translate("Debugger_for_chatClass", "Debugger_for_chat", 0, QApplication::UnicodeUTF8));
        pushButtonSend->setText(QApplication::translate("Debugger_for_chatClass", "Send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Debugger_for_chatClass: public Ui_Debugger_for_chatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGGER_FOR_CHAT_H
