#include "network_chat.h"


Network_chat::Network_chat(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	setup_ui_chat(false);

	// connect buttons
	connect(ui.pushButtonJoin, SIGNAL(clicked()), this, SLOT(join_chat()));
	connect(ui.pushButtonLeave, SIGNAL(clicked()), this, SLOT(leave_chat()));
	
	connect(ui.pushButtonSend, SIGNAL(clicked()), this, SLOT(test_send()));
}

Network_chat::~Network_chat()
{

}

void Network_chat::test_send() {
	//net->send_hello(ui.lineEditNick->text() + " " + QString::number(rand() % 100));
	//net->send_accepted(QHostAddress("127.0.0.1"), "nick", 4234234);
	//net->send_keepalive();

}

void Network_chat::print_message(QString const& message) {
	QString hist = ui.plainTextEditChat->toPlainText();
	ui.plainTextEditChat->setPlainText(hist + message + "\r");
}

void Network_chat::join_chat() {
	QString nick = ui.lineEditNick->text();
	net = new network(this, nick);

	// connect
	connect(net, SIGNAL(print_message(QString const&)), this, SLOT(print_message(QString const&)));

	net->in_chat = true;
	setup_ui_chat(true);

	net->send_hello(nick);
}

void Network_chat::leave_chat() {
	net->in_chat = false;
	setup_ui_chat(false);

	net->send_quit();
}



void Network_chat::setup_ui_chat(bool in_chat) {
	ui.plainTextEditChat->clear();
	ui.plainTextEditPeers->clear();
	ui.lineEditMessage->clear();
	ui.checkBox->setEnabled(true);

	// buttons
	ui.pushButtonJoin->setEnabled(!in_chat);
	ui.pushButtonLeave->setEnabled(in_chat);
	ui.pushButtonSend->setEnabled(in_chat);

	// text edits
	ui.plainTextEditChat->setEnabled(in_chat);
	ui.plainTextEditPeers->setEnabled(in_chat);
	ui.lineEditMessage->setEnabled(in_chat);
	ui.lineEditNick->setEnabled(!in_chat);
}
