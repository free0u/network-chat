#include "network_chat.h"


Network_chat::Network_chat(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	setup_ui_chat(false);

	// connect buttons
	connect(ui.pushButtonJoin, SIGNAL(clicked()), this, SLOT(join_chat()));
	connect(ui.pushButtonLeave, SIGNAL(clicked()), this, SLOT(leave_chat()));
	connect(ui.pushButtonSend, SIGNAL(clicked()), this, SLOT(send_message()));

}

Network_chat::~Network_chat()
{

}

void Network_chat::send_message() {
	QString message = ui.lineEditMessage->text();
	net->send_message_from_text(message);
	ui.lineEditMessage->setText("");
}

void Network_chat::print_message(QString const& message) {
	QString hist = ui.textBrowserChat->toPlainText();
	
	ui.textBrowserChat->setPlainText(hist + message + "\r");
}

void Network_chat::update_client_list() {
	QString data = "";
	QVector<client_info> clients = net->clients;
	for (int i = 0; i < clients.size(); ++i) {
		QString client = clients[i].nick + " [" + clients[i].ip.toString() + "]\r";
		data += client;
	}
	ui.textBrowserPeers->setPlainText(data);
}

void Network_chat::join_chat() {
	QString nick = ui.lineEditNick->text();
	net = new network(this, nick);

	// setup iface
	int ind = ui.comboBox->currentIndex();
	net->socket->setMulticastInterface(ifaces[ind]);

	// connect
	connect(net, SIGNAL(print_message(QString const&)), this, SLOT(print_message(QString const&)));
	connect(net, SIGNAL(update_client_list()), this, SLOT(update_client_list()));

	net->in_chat = true;
	setup_ui_chat(true);

	net->send_hello(nick);
}

void Network_chat::leave_chat() {
	net->in_chat = false;
	setup_ui_chat(false);

	net->send_quit(net->my_ip());

	delete net;
}



void Network_chat::setup_ui_chat(bool in_chat) {
	ui.textBrowserChat->clear();
	ui.textBrowserPeers->clear();
	ui.lineEditMessage->clear();

	// buttons
	ui.pushButtonJoin->setEnabled(!in_chat);
	ui.pushButtonLeave->setEnabled(in_chat);
	ui.pushButtonSend->setEnabled(in_chat);

	// text edits
	ui.textBrowserChat->setEnabled(in_chat);
	ui.textBrowserPeers->setEnabled(in_chat);
	ui.lineEditMessage->setEnabled(in_chat);
	ui.lineEditNick->setEnabled(!in_chat);

	// setup combobox
	if (!in_chat) {
		ui.comboBox->clear();
		ifaces = QNetworkInterface::allInterfaces();
		for (int i = 0; i < ifaces.size(); ++i) {
			ui.comboBox->addItem(ifaces[i].humanReadableName());
		}
	}
	ui.comboBox->setEnabled(!in_chat);
}
