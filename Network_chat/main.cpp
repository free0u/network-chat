#include "network_chat.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	Network_chat w;
	w.show();
	w.setFixedSize(w.geometry().width(),w.geometry().height());
	return a.exec();
}
