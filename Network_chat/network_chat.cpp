#include "network_chat.h"


Network_chat::Network_chat(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	net = new network(this);
	in_chat = false;
	setup_ui_chat();

	// connect
	connect(net, SIGNAL(print_message(QString const&)), this, SLOT(print_message(QString const&)));

	// connect buttons
	connect(ui.pushButtonJoin, SIGNAL(clicked()), this, SLOT(press_join_button()));
	connect(ui.pushButtonLeave, SIGNAL(clicked()), this, SLOT(press_leave_button()));

}

Network_chat::~Network_chat()
{

}

void Network_chat::print_message(QString const& message) {
	QString hist = ui.plainTextEditChat->toPlainText();
	ui.plainTextEditChat->setPlainText(hist + message + "\r");
}

void Network_chat::press_join_button() {
	in_chat = true;
	QString nick = ui.lineEditNick->text();
	setup_ui_chat();
	qDebug() << "Join: " + nick;
}

void Network_chat::press_leave_button() {
	in_chat = false;
	QString nick = ui.lineEditNick->text();
	setup_ui_chat();
	qDebug() << "Leave: " + nick;
}



void Network_chat::setup_ui_chat() {
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
