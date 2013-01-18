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
	
private:
	Ui::Network_chatClass ui;
	network *net;
	QList<QNetworkInterface> ifaces;
	void setup_ui_chat(bool in_chat);

public slots:
	void print_message(QString const&);
	void update_client_list();

private slots:
	void join_chat();
	void leave_chat();
	void send_message();
};

#endif // NETWORK_CHAT_H
