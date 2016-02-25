#ifndef JOCIRCLENXAPP_H
#define JOCIRCLENXAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_jocirclenxapp.h"
#include <QWidget>
#include <QtNetwork>
#include <QMessageBox>
//#include <iostream>
#include <QTimer>
#include <ctype.h>
#include <string>
#include <time.h>
//#include <vector>

class joCirclenXapp : public QMainWindow
{
	Q_OBJECT

public:
	joCirclenXapp(QWidget *parent = 0);
	~joCirclenXapp();
	int turn = 0;

public slots:

	void blockButtons();
	std::string checkNewGame(QString msg);
	bool chooseTeam(int t);
	void clientSend();
	std::string convertXO(int num);
	void fillLCD(std::string tab);
	std::string getVoteState(QString msg);
	std::string getTurn(std::string withoutState);
	std::string getGameState(std::string withoutTurn);
	int getWinner(std::string msg);
	void initButtons();
	void initClient();
	bool isNewGame(QString msg);
	void newGame();
	void onTimeout();
	void readFromServ();
	void sendTeam(int t);
	void readFromLabel();
	void sendMove(QString move);
	void showGameOver(int winner);
	void setTurn(int turn);
	void setElement(int i, int element);
	void setGameState(std::string game);
	void setVisibleLabel();

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
	//bool validateMsg(string lcdArray);

private:
	
	Ui::joCirclenXappClass ui;


};

#endif // JOCIRCLENXAPP_H
