#ifndef NETWORK_CHAT_H
#define NETWORK_CHAT_H

#include <QtGui/QMainWindow>
#include "ui_network_chat.h"

class Network_chat : public QMainWindow
{
	Q_OBJECT

public:
	Network_chat(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Network_chat();

private:
	Ui::Network_chatClass ui;
};

#endif // NETWORK_CHAT_H
