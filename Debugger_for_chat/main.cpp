#include "debugger_for_chat.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Debugger_for_chat w;
	w.show();
	return a.exec();
}
