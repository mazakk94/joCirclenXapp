#ifndef JOCIRCLENXAPP_H
#define JOCIRCLENXAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_jocirclenxapp.h"
#include <QWidget>
#include <QtNetwork>
//#include <iostream>
//#include <string>
//#include <vector>

class joCirclenXapp : public QMainWindow
{
	Q_OBJECT

public:


	void clientSend();
	void readFromServ();
	void startClient();
	joCirclenXapp(QWidget *parent = 0);
	~joCirclenXapp();

private:
	Ui::joCirclenXappClass ui;
};

#endif // JOCIRCLENXAPP_H
