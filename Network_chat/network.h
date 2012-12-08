#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtNetwork>

class network : public QObject
{
	Q_OBJECT

public:
	network(QObject *parent);
	~network();

	void gen_sig(QString const& message) {
		emit print_message(message);
	}

signals:
	void print_message(QString const&);

private slots:
	void read_message();

private:
	QUdpSocket *socket;
};

#endif // NETWORK_H
