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
	void press_join_button();
	void press_leave_button();

private:
	Ui::Network_chatClass ui;
	network *net;
	bool in_chat;

	void setup_ui_chat();
};

#endif // NETWORK_CHAT_H
