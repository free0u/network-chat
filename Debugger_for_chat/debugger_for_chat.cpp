#include "debugger_for_chat.h"

Debugger_for_chat::Debugger_for_chat(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	cnt_msg = 0;
	sok = new QUdpSocket(this);
	sok->bind(3141, QUdpSocket::ShareAddress);
	connect(sok, SIGNAL(readyRead()), this, SLOT(showMessage()));
	connect(ui.pushButtonSend, SIGNAL(clicked()), this, SLOT(sendMessage()));
	connect(ui.pushButtonClear, SIGNAL(clicked()), this, SLOT(clear_field()));
}

Debugger_for_chat::~Debugger_for_chat()
{

}

void Debugger_for_chat::sendMessage() {
	QString msg = ui.lineEditChat->text();
	msg += "\r\n";
	QByteArray data = msg.toUtf8();
	sok->writeDatagram(data.data(), QHostAddress::Broadcast, 3141);
	msg = "send: " + msg;
	print_message(msg);
}

void Debugger_for_chat::showMessage() {
	while (sok->hasPendingDatagrams()) {
		QByteArray data;
		data.resize(sok->pendingDatagramSize());
		QHostAddress host;
		sok->readDatagram(data.data(), data.size(), &host);
		bool res = is_my_ip(host);
		if (!is_my_ip(host)) {
			QString m = data.data();
			m = "receive: " + m;
			print_message(m);
		}
	}
}

void Debugger_for_chat::clear_field() {
	ui.plainTextEdit->setPlainText("");
}

void Debugger_for_chat::print_message(QString const& message) {
	QString hist = ui.plainTextEdit->toPlainText();
	hist += (message + '\r');
	ui.plainTextEdit->setPlainText(hist);
}

bool Debugger_for_chat::is_my_ip(QHostAddress &host) {
	QList<QHostAddress> addr = QNetworkInterface::allAddresses();
	for (size_t i = 0; i < addr.size(); ++i) {
		if (addr[i] == host) return true;
	}
	return false;
}