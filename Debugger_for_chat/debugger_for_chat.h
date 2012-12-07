#ifndef DEBUGGER_FOR_CHAT_H
#define DEBUGGER_FOR_CHAT_H

#include <QtGui/QMainWindow>
#include "ui_debugger_for_chat.h"

class Debugger_for_chat : public QMainWindow
{
	Q_OBJECT

public:
	Debugger_for_chat(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Debugger_for_chat();

private:
	Ui::Debugger_for_chatClass ui;
};

#endif // DEBUGGER_FOR_CHAT_H
