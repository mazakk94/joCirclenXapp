#include "jocirclenxapp.h"
#include <QMessageBox>
 //isdigit()
//#include <string>


// QString::fromUtf8(isTeam1)

using namespace std;

QTcpSocket *clientSock;
int team = 0;
bool teamChosen = false;
bool alreadyInit = false;
bool playerMoved = false;

bool joCirclenXapp::chooseTeam(int t){
	if (!teamChosen){
		team = t;
		teamChosen = true;
	}
	return teamChosen;
}

void joCirclenXapp::clientSend() {
	if (teamChosen){
		QString msg(ui.messageEdit->text());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	} else {
		QString str("wybierz team!");
		ui.messageBox->append(str);
	}
}

void joCirclenXapp::fillLCD(string tabq){

	string tabl = tabq.substr(0,9);
	vector<int> tab;
	for (int i = 0; i < tabl.size(); i++)
		tab.push_back(tabl[i] - (int)48);

	ui.messageEdit->setText(QString::number(tab.size()));
	ui.lcd1->setText(QString::number(tab[0]));
	ui.lcd2->setText(QString::number(tab[1]));
	ui.lcd3->setText(QString::number(tab[2]));
	ui.lcd4->setText(QString::number(tab[3]));
	ui.lcd5->setText(QString::number(tab[4]));
	ui.lcd6->setText(QString::number(tab[5]));
	ui.lcd7->setText(QString::number(tab[6]));
	ui.lcd8->setText(QString::number(tab[7]));
	ui.lcd9->setText(QString::number(tab[8]));
}

void joCirclenXapp::initClient(){
	/*QString str("init");
	ui.messageBox->append(str);*/
	if (!alreadyInit){
		if (chooseTeam(team)) {
			startClient();
			sendTeam(team);
			alreadyInit = true;
			ui.teamLabel->setText(QString::number(team));
		}
	} else {
		QString str("juz wybrales team!");
		ui.messageBox->append(str);
	}

}

void joCirclenXapp::readFromServ() {

	QByteArray temp = clientSock->readAll();
	QString msg(temp);
	
	string lcdArray = "";
	if (msg.length() > 9){
		lcdArray = msg.toStdString().substr(0, 9);	//pierwsze 9 znakow to stan planszy
	} else {
		QString tmp = "bledna wiadomosc z serwera" + QString::number(msg.length());
		ui.messageBox->append(tmp);
	}
	bool flag = true;
	for (int i = 0; i < lcdArray.size(); i++)
		if (!isdigit(lcdArray[i]))
			flag = false;
	

	if (flag){
		fillLCD(lcdArray);
	} else {
		ui.messageBox->append("bledna wiadomosc z serwera 2!");
	}
	string newmsg = "";
	if (msg.size()>9)
		newmsg = msg.toStdString().substr(9);  //od 9 znaku wiadomosc
	
	QString str = QString::fromStdString(newmsg);
	ui.messageBox->append(str);

	//ui.messageBox->append(str);

	//int x = str.split(" ")[0].toInt();
}

void joCirclenXapp::sendTeam(int t){
	
	QString msg(QString::number(t));
	QByteArray msgbyte = msg.toUtf8();
	ui.messageEdit->text() = msgbyte;
	clientSock->write(msgbyte);
}

void joCirclenXapp::readFromLabel(){
	QString str(ui.teamLabel->text());

}

void joCirclenXapp::sendMove(QString move){
	int intmove = move.split(" ")[0].toInt();
	intmove--;

	if (teamChosen){
		if (!playerMoved){
			QString num = QString::number(intmove);
			QByteArray msgbyte = num.toUtf8();
			clientSock->write(msgbyte);
		} else {
			QString str("juz wykonales ruch!");
			ui.messageBox->append(str);
		}
		
	}
	else {
		QString str("wybierz team!");
		ui.messageBox->append(str);
	}
}

void joCirclenXapp::setMove1(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("1");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove2(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("2");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove3(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("3");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove4(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("4");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove5(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("5");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove6(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("6");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove7(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("7");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove8(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("8");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}
void joCirclenXapp::setMove9(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("9");
	sendMove(ui.moveLabel->text());
	playerMoved = true;

}

void joCirclenXapp::startClient() {

	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &joCirclenXapp::readFromServ);
	clientSock->connectToHost("localhost", 1111);

	//QString text = "Wybierz slot gracza:";	//ui.fJoinToServ->setText(text);	//unlockButtons();
}

void joCirclenXapp::team1(){
	chooseTeam(1);
}
void joCirclenXapp::team2(){
	chooseTeam(2);
}
/*
bool joCirclenXapp::validateMsg(string lcdArray){
	for (int i = 0; i < lcdArray.size(); i++)
		if (!isdigit(lcdArray[i]))
			return false;
	return true;
}
*/

joCirclenXapp::joCirclenXapp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	QObject::connect(ui.sendButton, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.team1, SIGNAL(clicked()), this, SLOT(team1()));
	QObject::connect(ui.team1, SIGNAL(clicked()), this, SLOT(initClient()));
	QObject::connect(ui.team2, SIGNAL(clicked()), this, SLOT(team2()));
	QObject::connect(ui.team2, SIGNAL(clicked()), this, SLOT(initClient()));
	{
		QObject::connect(ui.b1, SIGNAL(clicked()), this, SLOT(setMove1()));
		QObject::connect(ui.b2, SIGNAL(clicked()), this, SLOT(setMove2()));
		QObject::connect(ui.b3, SIGNAL(clicked()), this, SLOT(setMove3()));
		QObject::connect(ui.b4, SIGNAL(clicked()), this, SLOT(setMove4()));
		QObject::connect(ui.b5, SIGNAL(clicked()), this, SLOT(setMove5()));
		QObject::connect(ui.b6, SIGNAL(clicked()), this, SLOT(setMove6()));
		QObject::connect(ui.b7, SIGNAL(clicked()), this, SLOT(setMove7()));
		QObject::connect(ui.b8, SIGNAL(clicked()), this, SLOT(setMove8()));
		QObject::connect(ui.b9, SIGNAL(clicked()), this, SLOT(setMove9()));
	}
}

joCirclenXapp::~joCirclenXapp() { }