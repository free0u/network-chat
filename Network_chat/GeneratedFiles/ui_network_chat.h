/********************************************************************************
** Form generated from reading UI file 'network_chat.ui'
**
** Created: Sat 8. Dec 18:53:01 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Network_chatClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditMessage;
    QPushButton *pushButtonSend;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNick;
    QPushButton *pushButtonJoin;
    QPushButton *pushButtonLeave;
    QCheckBox *checkBox;
    QLabel *label_3;
    QLabel *label_2;
    QPlainTextEdit *plainTextEditChat;
    QPlainTextEdit *plainTextEditPeers;

    void setupUi(QMainWindow *Network_chatClass)
    {
        if (Network_chatClass->objectName().isEmpty())
            Network_chatClass->setObjectName(QString::fromUtf8("Network_chatClass"));
        Network_chatClass->resize(526, 462);
        centralWidget = new QWidget(Network_chatClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 511, 441));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditMessage = new QLineEdit(widget);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));

        horizontalLayout_2->addWidget(lineEditMessage);

        pushButtonSend = new QPushButton(widget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout_2->addWidget(pushButtonSend);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditNick = new QLineEdit(widget);
        lineEditNick->setObjectName(QString::fromUtf8("lineEditNick"));

        horizontalLayout->addWidget(lineEditNick);

        pushButtonJoin = new QPushButton(widget);
        pushButtonJoin->setObjectName(QString::fromUtf8("pushButtonJoin"));

        horizontalLayout->addWidget(pushButtonJoin);

        pushButtonLeave = new QPushButton(widget);
        pushButtonLeave->setObjectName(QString::fromUtf8("pushButtonLeave"));

        horizontalLayout->addWidget(pushButtonLeave);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        plainTextEditChat = new QPlainTextEdit(widget);
        plainTextEditChat->setObjectName(QString::fromUtf8("plainTextEditChat"));

        gridLayout->addWidget(plainTextEditChat, 2, 0, 1, 1);

        plainTextEditPeers = new QPlainTextEdit(widget);
        plainTextEditPeers->setObjectName(QString::fromUtf8("plainTextEditPeers"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEditPeers->sizePolicy().hasHeightForWidth());
        plainTextEditPeers->setSizePolicy(sizePolicy);
        plainTextEditPeers->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(plainTextEditPeers, 2, 1, 1, 1);

        Network_chatClass->setCentralWidget(centralWidget);
        lineEditMessage->raise();
        pushButtonSend->raise();
        lineEditMessage->raise();
        checkBox->raise();
        checkBox->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(Network_chatClass);

        QMetaObject::connectSlotsByName(Network_chatClass);
    } // setupUi

    void retranslateUi(QMainWindow *Network_chatClass)
    {
        Network_chatClass->setWindowTitle(QApplication::translate("Network_chatClass", "Network_chat", 0, QApplication::UnicodeUTF8));
        pushButtonSend->setText(QApplication::translate("Network_chatClass", "Send", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Network_chatClass", "Nick:", 0, QApplication::UnicodeUTF8));
        pushButtonJoin->setText(QApplication::translate("Network_chatClass", "Join chat", 0, QApplication::UnicodeUTF8));
        pushButtonLeave->setText(QApplication::translate("Network_chatClass", "Leave chat", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Network_chatClass", "local peer discovery", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Network_chatClass", "Peers:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Network_chatClass", "History:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Network_chatClass: public Ui_Network_chatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_CHAT_H
