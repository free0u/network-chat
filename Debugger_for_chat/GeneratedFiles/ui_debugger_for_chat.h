/********************************************************************************
** Form generated from reading UI file 'debugger_for_chat.ui'
**
** Created: Sat 8. Dec 19:13:57 2012
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Debugger_for_chatClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditChat;
    QPushButton *pushButtonSend;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *Debugger_for_chatClass)
    {
        if (Debugger_for_chatClass->objectName().isEmpty())
            Debugger_for_chatClass->setObjectName(QString::fromUtf8("Debugger_for_chatClass"));
        Debugger_for_chatClass->resize(373, 400);
        centralWidget = new QWidget(Debugger_for_chatClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 351, 381));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditChat = new QLineEdit(widget);
        lineEditChat->setObjectName(QString::fromUtf8("lineEditChat"));

        horizontalLayout->addWidget(lineEditChat);

        pushButtonSend = new QPushButton(widget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout->addWidget(pushButtonSend);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        Debugger_for_chatClass->setCentralWidget(centralWidget);

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
