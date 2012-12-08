#include "debugger_for_chat.h"


Debugger_for_chat::Debugger_for_chat(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	cnt_msg = 0;
	sok = new QUdpSocket(this);
	sok->bind(31313, QUdpSocket::ShareAddress);
	connect(sok, SIGNAL(readyRead()), this, SLOT(showMessage()));
	connect(ui.pushButtonSend, SIGNAL(clicked()), this, SLOT(sendMessage()));
}

Debugger_for_chat::~Debugger_for_chat()
{

}

void Debugger_for_chat::sendMessage() {
	QString msg = ui.lineEditChat->text();
	QByteArray data = msg.toUtf8();
	sok->writeDatagram(data.data(), QHostAddress::Broadcast, 31313);
}

void Debugger_for_chat::showMessage() {
	while (sok->hasPendingDatagrams()) {
		QByteArray data;
		data.resize(sok->pendingDatagramSize());
		sok->readDatagram(data.data(), data.size());
		ui.textBrowserChat->setText(data.data());
	}
}