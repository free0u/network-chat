#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtNetwork>

class network : public QObject
{
	Q_OBJECT

public:
	network(QObject *parent, QString const& nick);
	~network();

	void gen_sig(QString const& message) {
		emit print_message(message);
	}

signals:
	void print_message(QString const&);

private slots:
	void read_message();

public:
	void send_broadcast_command(QString const& message);
	void send_command(QString const& message, QHostAddress const& host);

	// commands
	void send_response(QHostAddress const& dest, QString const& my_nick, QVector<QHostAddress> const& ips, QVector<QString> const& nicks);
	void send_join(QHostAddress const& ip, QString const& nick);
	void send_message(QHostAddress const& ip, QString const& nick, int time, QString const& message);
	void send_accepted(QHostAddress const& dest, QString const& nick, int time);
	
	void send_keepalive();

	QHostAddress my_ip();
	bool is_my_ip(QHostAddress &host);

	bool in_chat;
	void send_hello(QString const& nick); // TODO 30 sec interval
	void send_quit();

	void parse_message(QString const& message);
private:
	QUdpSocket *socket;
	QString nick;

};

#endif // NETWORK_H
