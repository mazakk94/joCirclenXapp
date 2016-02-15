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
	joCirclenXapp(QWidget *parent = 0);
	~joCirclenXapp();

public slots:

	bool chooseTeam(int t);
	void clientSend();
	void initClient();
	void readFromServ();
	void sendTeam(int t);

	void setMove1();
	void setMove2();
	void setMove3();
	void setMove4();
	void setMove5();
	void setMove6();
	void setMove7();
	void setMove8();
	void setMove9();

	void startClient();
	void team1();
	void team2();

private:
	Ui::joCirclenXappClass ui;


};

#endif // JOCIRCLENXAPP_H
