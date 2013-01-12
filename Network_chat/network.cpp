#include "network.h"

network::network(QObject *parent, QString const& nick)
	: QObject(parent), nick(nick), in_chat(true)
{
	socket = new QUdpSocket(this);
	socket->bind(31313, QUdpSocket::ShareAddress);
	connect(socket, SIGNAL(readyRead()), this, SLOT(read_message()));
}

// slot
void network::read_message() {
	QString message = "";
	while (socket->hasPendingDatagrams()) {
		QByteArray data;
		data.resize(socket->pendingDatagramSize());
		QHostAddress host;
		socket->readDatagram(data.data(), data.size(), &host);
		if (!is_my_ip(host)) {
			message += data.data();
		}
	}
	if (!message.isEmpty()) {
		emit print_message(message); // signal
		parse_message(message);
	}
}

void network::send_broadcast_command(QString const& message) {
	QByteArray datagram = message.toUtf8();
	socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 31313);
}

void network::send_command(QString const& message, QHostAddress const& host) {
	QByteArray datagram = message.toUtf8();
	socket->writeDatagram(datagram.data(), datagram.size(), host, 31313);
}

void network::send_hello(QString const& nick) {
	QString mes = "HELLO " + nick + "\r\n";
	send_broadcast_command(mes);
}

void network::send_response(QHostAddress const& dest, QString const& my_nick, QVector<QHostAddress> const& ips, QVector<QString> const& nicks) { // TODO don't broadcast
	QString mes = "RESPONSE " + my_nick;
	for (int i = 0; i < ips.size(); ++i) {
		mes += " " + ips[i].toString();
		mes += " " + nicks[i];
	}
	mes += "\r\n";
	send_broadcast_command(mes);
}

void network::send_join(QHostAddress const& ip, QString const& nick) { // TODO don't broadcast
	QString mes = "JOIN " + ip.toString() + " " + nic + "\r\n";
	send_broadcast_command(mes);
}

void network::send_accepted(QHostAddress const& dest, QString const& nick, int time) { // TODO don't broadcast
	QString mes = "ACCEPTED " + nick + " " + QString::number(time) + "\r\n";
	send_broadcast_command(mes);
}

void network::send_quit() {
	QString mes = "QUIT " + my_ip().toString() + "\r\n";
	send_broadcast_command(mes); // TODO don't broadcast
}

void network::send_keepalive() {
	QString mes = "KEEPALIVE\r\n";
	send_broadcast_command(mes); // TODO don't broadcast
}


void network::parse_message(QString const& message) {
	
}


QHostAddress network::my_ip() {
	QList<QHostAddress> addr = QNetworkInterface::allAddresses();
	
	for (size_t i = 0; i < addr.size(); ++i) {\
		QHostAddress a = QHostAddress(addr[i].toIPv4Address());
		if (a != QHostAddress("0.0.0.0") && a != QHostAddress("127.0.0.1")) {
			return a;
		}
	}
	return QHostAddress("127.0.0.1");
}

bool network::is_my_ip(QHostAddress &host) {
	QHostAddress my = my_ip();
	return host == my_ip();
	
	//qDebug() << my_ip();

	QList<QHostAddress> addr = QNetworkInterface::allAddresses();
	for (size_t i = 0; i < addr.size(); ++i) {
		if (addr[i] == host) return true;
	}
	return false;
}

network::~network()
{
	if (in_chat) {
		in_chat = false;
		send_quit();
	}
}
