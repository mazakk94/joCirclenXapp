#include "jocirclenxapp.h"
#include <QMessageBox>
//#include <string>


// QString::fromUtf8(isTeam1)

QTcpSocket *clientSock;

void joCirclenXapp::clientSend() {
	QString msg(ui.messageEdit->text().toUtf8());
	QByteArray msgbyte = msg.toUtf8();
	clientSock->write(msgbyte);
}



void joCirclenXapp::readFromServ() {

	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);

	
	ui.messageBox->append(str);

	int x = str.split(" ")[0].toInt();

	
}


void joCirclenXapp::startClient() {

	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &joCirclenXapp::readFromServ);
	clientSock->connectToHost("localhost", 1111);

	//QString text = "Wybierz slot gracza:";	//ui.fJoinToServ->setText(text);	//unlockButtons();
}




joCirclenXapp::joCirclenXapp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.sendButton, SIGNAL(clicked()), this, SLOT(clientSend()));
}

joCirclenXapp::~joCirclenXapp()
{

}
