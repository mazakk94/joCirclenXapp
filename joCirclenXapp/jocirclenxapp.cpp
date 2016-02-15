#include "jocirclenxapp.h"
#include <QMessageBox>
//#include <string>


// QString::fromUtf8(isTeam1)

using namespace std;
QTcpSocket *clientSock;
int team = 0;
bool teamChosen = false;
bool alreadyInit = false;

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

	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);

	
	ui.messageBox->append(str);

	int x = str.split(" ")[0].toInt();
}

void joCirclenXapp::sendTeam(int t){
	
	QString msg(QString::number(t));
	QByteArray msgbyte = msg.toUtf8();
	ui.messageEdit->text() = msgbyte;
	clientSock->write(msgbyte);
}

void joCirclenXapp::setMove1(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("1");
}
void joCirclenXapp::setMove2(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("2");
}
void joCirclenXapp::setMove3(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("3");
}
void joCirclenXapp::setMove4(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("4");
}
void joCirclenXapp::setMove5(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("5");
}
void joCirclenXapp::setMove6(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("6");
}
void joCirclenXapp::setMove7(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("7");
}
void joCirclenXapp::setMove8(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("8");
}
void joCirclenXapp::setMove9(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("9");
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