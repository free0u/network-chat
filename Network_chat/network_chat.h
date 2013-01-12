#ifndef NETWORK_CHAT_H
#define NETWORK_CHAT_H

#include <QtGui/QMainWindow>
#include <qdebug.h>
#include "ui_network_chat.h"
#include "network.h"

class Network_chat : public QMainWindow
{
	Q_OBJECT

public:
	Network_chat(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Network_chat();

public slots:
	void print_message(QString const&);

private slots:
	void join_chat();
	void leave_chat();
	void test_send();

private:
	Ui::Network_chatClass ui;
	network *net;

	void setup_ui_chat(bool in_chat);
};

#endif // NETWORK_CHAT_H
