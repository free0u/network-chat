#include "network_chat.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Network_chat w;
	w.show();
	return a.exec();
}
