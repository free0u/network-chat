#include "network.h"

network::network(QObject *parent)
	: QObject(parent)
{
	socket = new QUdpSocket(this);
	socket->bind(31313, QUdpSocket::ShareAddress);

	connect(socket, SIGNAL(readyRead()), this, SLOT(read_message()));
}

void network::read_message() {
	QString message = "";
	while (socket->hasPendingDatagrams()) {
		QByteArray data;
		data.resize(socket->pendingDatagramSize());
		socket->readDatagram(data.data(), data.size());
		message += data.data();
	}
	emit print_message(message);
}

network::~network()
{

}
