#ifndef DEBUGGER_FOR_CHAT_H
#define DEBUGGER_FOR_CHAT_H

#include <QtGui/QMainWindow>
#include "ui_debugger_for_chat.h"

#include <qdebug.h>
#include <QtNetwork>
#include <QString>
#include <iostream>
using namespace std;

class Debugger_for_chat : public QMainWindow
{
	Q_OBJECT

public:
	Debugger_for_chat(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Debugger_for_chat();

private slots:
	void showMessage();
	void sendMessage();

private:
	Ui::Debugger_for_chatClass ui;
	QUdpSocket *sok;
	int cnt_msg;

	void print_message(QString const& message);
};

#endif // DEBUGGER_FOR_CHAT_H
