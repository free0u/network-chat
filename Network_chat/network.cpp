#include "network.h"

network::network(QObject *parent, QString const& nick)
	: QObject(parent), my_nick(nick), in_chat(true)
{
	port = 3141;


	socket = new QUdpSocket(this);
	socket->bind(port, QUdpSocket::ShareAddress);
	connect(socket, SIGNAL(readyRead()), this, SLOT(read_message()));

	timer_alive = new QTimer(this);
	connect(timer_alive, SIGNAL(timeout()), this, SLOT(keepalive()));

	timer_alive->start(1000 * 2 * 60); // 2 mins

	// hello timer
	timer_hello = new QTimer(this);
	connect(timer_hello, SIGNAL(timeout()), this, SLOT(timer_hello_is_timeout()));
	timer_hello->start(1000 * 30); // 30 sec

	// message_sending timer
	timer_message_sending = new QTimer(this);
	connect(timer_message_sending, SIGNAL(timeout()), this, SLOT(resend_messages()));
	timer_message_sending->start(1000 * 60); // 1 min


	file = new QFile("log.txt");
	file->open(QIODevice::WriteOnly | QIODevice::Text);

	out = new QTextStream(file);

}

void network::keepalive() {
	// kill don't alive clients
	for (int i = 0; i < clients.size(); ++i) {
		send_keepalive(clients[i].ip);

		int d = time(NULL) - clients[i].last_active;
		if (d > 10 * 60) { // 10 mins
			send_quit(clients[i].ip);
			remove_client_by_ip(clients[i].ip);
		}
	}
}

void network::resend_messages() {
	for (int i = 0; i < pull_of_sending_messages.size(); ++i) {
		message_info info = pull_of_sending_messages[i];
		int d = info.time - time(NULL);
		if (d > 60) { // 1 min
			int time_send = time(NULL);
			pull_of_sending_messages[i].time = time_send;
			for (int i = 0; i < clients.size(); ++i) {
				send_message(clients[i].ip, info.ip, info.nick, time_send, info.message);
			}
		}
	}
}

void network::timer_hello_is_timeout() {
	if (clients.size() > 0) {
		timer_hello->stop();
	} else {
		send_hello(my_nick);
	}
}

// slot
void network::read_message() {
	QString message = "";
	QHostAddress host;
	while (socket->hasPendingDatagrams()) {
		QByteArray data;
		data.resize(socket->pendingDatagramSize());
		socket->readDatagram(data.data(), data.size(), &host);

		//qDebug() << "recieved: ";
		//qDebug() << data.data();

		if (!is_my_ip(host)) {
			message = data.data();
			parse_message(message, host);
		}
	}
}

void network::send_broadcast_command(QString const& message) {
	//qDebug() << "send: ";
	//qDebug() << message;

	QByteArray datagram = message.toUtf8();
	socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, port);
}

void network::send_command(QString const& message, QHostAddress const& host) {
	//qDebug() << "send: ";
	//qDebug() << message;

	QByteArray datagram = message.toUtf8();
	socket->writeDatagram(datagram.data(), datagram.size(), host, port);
}

void network::send_hello(QString const& nick) {
	QString mes = "HELLO " + nick + "\r\n";
	send_broadcast_command(mes);
}

void network::send_response(QHostAddress const& dest) {
	QString mes = "RESPONSE " + my_nick;
	QHostAddress ip = my_ip();
	for (int i = 0; i < clients.size(); ++i) {
		if (clients[i].ip == ip) continue;
		mes += " " + clients[i].ip.toString();
		mes += " " + clients[i].nick;
	}
	mes += "\r\n";
	send_command(mes, dest);
}

void network::send_join(QHostAddress const& dest, QHostAddress const& ip, QString const& nick) {
	QString mes = "JOIN " + ip.toString() + " " + nick + "\r\n";
	send_command(mes, dest);
}

void network::send_message(QHostAddress const& dest, QHostAddress const& ip, QString const& nick, int time, QString const& message) {
	QString mes = "MESSAGE " + ip.toString() + " " + nick + " " + QString::number(time) + " " + message;
	mes += '\0';
	mes += "\r\n";
	send_command(mes, dest);
}

void network::send_accepted(QHostAddress const& dest, QString const& nick, int time) {
	QString mes = "ACCEPTED " + nick + " " + QString::number(time) + "\r\n";
	send_command(mes, dest);
}

void network::send_quit(QHostAddress const& ip) {
	QString mes = "QUIT " + ip.toString() + "\r\n";
	for (int i = 0; i < clients.size(); ++i) {
		send_command(mes, clients[i].ip);
	}
}

void network::send_keepalive(QHostAddress const& dest) {
	QString mes = "KEEPALIVE\r\n";
	send_command(mes, dest);
}

void network::add_client(QHostAddress const& ip, QString const& nick) {
	bool is_new_client = true;
	if (is_my_ip(ip)) return;
	for (int i = 0; i < clients.size(); ++i) {
		if (clients[i].ip == ip) {
			is_new_client = false;
			break;
		}
	}
	if (is_new_client) {
		clients.push_back(client_info(ip, nick, time(NULL)));
		emit update_client_list();
	}
}

void network::remove_client_by_ip(QHostAddress const& ip) {
	for (int i = 0; i < clients.size(); ++i) {
		if (clients[i].ip == ip) {
			clients.remove(i);
			break;
		}
	}
}


void network::parse_message(QString const& mes, QHostAddress const& dest) {
	QString message(mes);
	if (message.size() < 2) return;
	if (message.right(2) == "\r\n") {
		message.remove(message.size() - 2, 2);
	}

	QStringList tokens = message.split(' ');
	if (tokens.isEmpty()) return;
	
	QString cmd = tokens[0];
	
	if (cmd == "HELLO") { // HELLO 
		if (tokens.size() < 2) return;
		
		QString nick = tokens[1];

		send_response(dest);

		for (int i = 0; i < clients.size(); ++i) {
			if (clients[i].ip == dest) continue;
			send_join(clients[i].ip, dest, nick);
		}

		add_client(dest, nick);

		return;
	} 
	
	if (cmd == "RESPONSE") { // RESPONSE NICKNAME_0 IP_1 NICKNAME_1 IP_2 NICKNAME_2 � IP_n NICKNAME_n
		if (tokens.size() < 2) return;
		
		QString nick_0 = tokens[1];
		QVector<QHostAddress> ips;
		QVector<QString> nicks;
		
		int i = 2;
		while (i < tokens.size()) {
			ips.push_back(QHostAddress(tokens[i]));
			nicks.push_back(tokens[i + 1]);
			i += 2;
		}

		ips.push_back(dest);
		nicks.push_back(nick_0);

		for (int i = 0; i < ips.size(); ++i) {
			if (ips[i].isNull()) continue;
			add_client(ips[i], nicks[i]);
		}

		return;
	}
	
	if (cmd == "JOIN") { // JOIN IP NICKNAME
		if (tokens.size() < 3) return;

		QString nick = tokens[2];
		QHostAddress ip(tokens[1]);

		if (ip.isNull()) return;

		bool is_new_client = true;
		for (int i = 0; i < clients.size(); ++i) {
			if (clients[i].ip == dest) {
				is_new_client = false;
				break;
			}
		}
		
		if (is_new_client) {
			for (int i = 0; i < clients.size(); ++i) {
				send_join(clients[i].ip, dest, nick);
			}
			add_client(ip, nick);
		}

		return;
	}
	
	if (cmd == "MESSAGE") { // MESSAGE IP NICKNAME TIME MSG
		if (tokens.size() < 5) return;

		QHostAddress ip(tokens[1]);
		QString nick = tokens[2];
		int time_send = tokens[3].toInt();
		QString message = tokens[4];

		for (int i = 5; i < tokens.size(); ++i) {
			message += " ";
			message += tokens[i];
		}

		if (ip.isNull()) return;

		// known_host?
		bool known_host = false;
		for (int i = 0; i < clients.size(); ++i) {
			if (clients[i].ip == ip) {
				known_host = true;
				break;
			}
		}
		if (!known_host) {
			return;
		}

		send_accepted(dest, nick, time_send);

		int time_now = time(NULL);
		while (!history.isEmpty()) {
			int d = time_now - history[0].time;
			if (d > 60 * 60) { // 60 mins
				history.remove(0);
			} else
			{
				break;
			}
		}


		message_info info(nick, time_send);
		bool have_message = false;
		for (int i = 0; i < history.size(); ++i) {
			if (history[i] == info) {
				have_message = true;
				break;
			}
		}
		if (!have_message) {
			emit print_message(nick + ": " + message);

			history.push_back(info);
			for (int i = 0; i < clients.size(); ++i) {
				if (clients[i].ip == ip) continue;
				if (clients[i].ip == dest) continue;

				send_message(clients[i].ip, ip, nick, time_send, message);
			}
		}

		return;
	}
	
	if (cmd == "ACCEPTED") { // ACCEPTED NICKNAME TIME
		if (tokens.size() < 3) return;

		QString nick = tokens[1];
		int time = tokens[2].toInt();
		message_info cur_info(nick, time);

		for (int i = 0; i < pull_of_sending_messages.size(); ++i) {
			message_info info = pull_of_sending_messages[i];
			if (info == cur_info) {
				pull_of_sending_messages.remove(i);

				emit print_message(nick + ": " + info.message);
				info.message.clear();
				history.push_back(info);
				break;
			}
		}

		return;
	}
	
	if (cmd == "QUIT") { // QUIT IP
		if (tokens.size() < 2) return;

		QHostAddress ip(tokens[1]);

		if (ip.isNull()) return;

		bool known_host = false;
		for (int i = 0; i < clients.size(); ++i) {
			if (clients[i].ip == ip) {
				known_host = true;
				break;
			}
		}
		if (!known_host) {
			return;
		}
		send_quit(ip);

		remove_client_by_ip(ip);
		emit update_client_list();

		if (clients.isEmpty()) {
			timer_hello->start(1000 * 30); // 30 sec
		}

		return;
	}
	
	if (cmd == "GET") { // GET
		send_response(dest);
		return;
	}
	
	if (cmd == "KEEPALIVE") { // KEEPALIVE
		for (int i = 0; i < clients.size(); ++i) {
			if (clients[i].ip == dest) {
				clients[i].last_active = time(NULL);
				break;
			}
		}
	}
}

void network::send_message_from_text(QString const& message) {
	int time_send = time(NULL);
	pull_of_sending_messages.push_back(message_info(my_nick, time_send));
	pull_of_sending_messages.back().message = message;
	pull_of_sending_messages.back().ip = my_ip();
	

	for (int i = 0; i < clients.size(); ++i) {
		send_message(clients[i].ip, my_ip(), my_nick, time_send, message);
	}
}


QHostAddress network::my_ip() {
	QNetworkInterface iface = socket->multicastInterface();

	auto addr = iface.addressEntries();
	for (int i = 0; i < addr.size(); ++i) {
		QHostAddress ip = addr[i].ip();
		if (ip.protocol() == QAbstractSocket::IPv4Protocol) {
			return ip;
		}
	}
	return QHostAddress::Null;
}

bool network::is_my_ip(QHostAddress const& host) {
	return (my_ip() == host);
}

network::~network()
{
	if (in_chat) {
		in_chat = false;
		send_quit(my_ip());
	}

	file->close();
}
