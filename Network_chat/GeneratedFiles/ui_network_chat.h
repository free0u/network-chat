/********************************************************************************
** Form generated from reading UI file 'network_chat.ui'
**
** Created: Sat 8. Dec 16:28:19 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORK_CHAT_H
#define UI_NETWORK_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Network_chatClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Network_chatClass)
    {
        if (Network_chatClass->objectName().isEmpty())
            Network_chatClass->setObjectName(QString::fromUtf8("Network_chatClass"));
        Network_chatClass->resize(600, 400);
        menuBar = new QMenuBar(Network_chatClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Network_chatClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Network_chatClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Network_chatClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Network_chatClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Network_chatClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Network_chatClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Network_chatClass->setStatusBar(statusBar);

        retranslateUi(Network_chatClass);

        QMetaObject::connectSlotsByName(Network_chatClass);
    } // setupUi

    void retranslateUi(QMainWindow *Network_chatClass)
    {
        Network_chatClass->setWindowTitle(QApplication::translate("Network_chatClass", "Network_chat", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Network_chatClass: public Ui_Network_chatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_CHAT_H
