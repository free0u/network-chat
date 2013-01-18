#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtNetwork>
#include <QFile>

#include <ctime>
#include <stdexcept>

struct message_info {
	QString nick, message;
	int time;
	QHostAddress ip;
	message_info() {}
	message_info(QString const& nick, int  time) : nick(nick), time(time) {}

	bool operator == (message_info const& a) const {
		return nick == a.nick && time == a.time;
	}
};

struct client_info {
	QHostAddress ip;
	QString nick;
	int last_active;
	client_info() {}
	client_info(QHostAddress const& ip, QString const& nick, int time) :
		ip(ip), nick(nick), last_active(time) {}

	bool operator == (client_info const& a) const {
		return ip == a.ip;
	}
};

class network : public QObject
{
	Q_OBJECT

signals:
	void print_message(QString const&);
	void update_client_list();

public:
	network(QObject *parent, QString const& nick);
	~network();
	
	void send_message_from_text(QString const& message);
	void send_hello(QString const& nick);
	void send_quit(QHostAddress const& ip);
	QHostAddress my_ip();

	QVector<client_info> clients;
	bool in_chat;
	QUdpSocket *socket;



private:
	QString my_nick;
	QFile *file;
	QTextStream *out;

	void send_broadcast_command(QString const& message);
	void send_command(QString const& message, QHostAddress const& host);

	// commands
	void send_response(QHostAddress const& dest);
	void send_join(QHostAddress const& dest, QHostAddress const& ip, QString const& nick);
	void send_message(QHostAddress const& dest, QHostAddress const& ip, QString const& nick, int time, QString const& message);
	void send_accepted(QHostAddress const& dest, QString const& nick, int time);
	void send_keepalive(QHostAddress const& dest);
	
	

	bool is_my_ip(QHostAddress const& host);

	

	void add_client(QHostAddress const& ip, QString const& nick);
	void remove_client_by_ip(QHostAddress const& ip);
	void parse_message(QString const& message, QHostAddress const& dest);

	


	QVector<message_info> history, pull_of_sending_messages;
	int port;
	QTimer *timer_alive, *timer_hello, *timer_message_sending;

	
private slots:
	void read_message();
	void timer_hello_is_timeout();
	void keepalive();
	void resend_messages();

};

#endif // NETWORK_H
