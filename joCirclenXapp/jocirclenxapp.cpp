#include "jocirclenxapp.h"


/*
TODO:
[x] blokowanie wyslania ruchu dopiero gdy dostaniemy info o tym ze zostal zaakceptowany - wysylamy ruch
[ ] gui poprawic - rysowanie X i O
[ ] sprawdzic jak dziala na kilku kompach
[ ] adres IP do wpisania
[ ] problem z polaczeniem sie z serwerem - co wtedy?
[ ] okno koñca gry - wyswietlanie kto wygral i propozycja rozpoczecia nowej gry
[ ] new game - wszystko wyczyscic i na nowo
[ ] jezeli jest nowa gra to pokazujemy ukryty interfejs
*/

using namespace std;

QTcpSocket *clientSock;
vector<QPushButton*> buttons;
int team = 0;
bool teamChosen = false;
bool alreadyInit = false;
bool playerMoved = false;
bool connected = false;

void joCirclenXapp::blockButtons(){
	
	//buttons.push_back(ui.b1);
	for each (QPushButton* button in buttons) {
		if (button->text().toStdString().compare("0"))
			button->setEnabled(false);
		else
			button->setEnabled(true);
	}
}

string joCirclenXapp::checkNewGame(QString msg){
	string str = msg.toStdString().substr(0, 3);
	string str2 = "new";
	ui.messageBox->append("str1: " + QString::fromStdString(str));
	ui.messageBox->append("str2: " + QString::fromStdString(str2));
	if (str.compare(str2) == 0){ //koniec gry! dostalismy info od serwera
		ui.messageBox->append("string returnowany" + QString::fromStdString(msg.toStdString().substr(3)));
		return msg.toStdString().substr(3);
	} else {
		return msg.toStdString();
	}
}

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

string joCirclenXapp::getGameState(string withoutTurn){
	string game = "";
	game += withoutTurn.substr(0, 9);
	ui.messageBox->append(QString::fromStdString(game));
	

	return withoutTurn.substr(9);
}

string joCirclenXapp::getVoteState(QString msg){
	string new_message = "";

	string lcdArray = "";
	if (msg.length() > 9){
		lcdArray = msg.toStdString().substr(0, 9);	//pierwsze 9 znakow to stan planszy
	} else {
		QString tmp = "bledna wiadomosc z serwera" + QString::number(msg.length());
		ui.messageBox->append(tmp);
	}
	bool flag = true;
	for (int i = 0; i < lcdArray.size(); i++){
		if (!isdigit(lcdArray[i])){
			flag = false;
			break;
		}
	}

	if (flag)
		fillLCD(lcdArray);
	else 
		ui.messageBox->append("bledna wiadomosc z serwera 2!");
	
	
	if (msg.size()>9)
		new_message = msg.toStdString().substr(9);  //od 9 znaku wiadomosc

	return new_message;
}

string joCirclenXapp::getTurn(string withoutState){
	
	//ui.messageBox->append("Without state: " + QString::fromStdString(withoutState));
	string new_msg = "";
	
	new_msg = withoutState.substr(1);
	return new_msg;
}

void joCirclenXapp::initButtons(){
	buttons.clear();
	buttons.push_back(ui.b1);
	buttons.push_back(ui.b2);
	buttons.push_back(ui.b3);
	buttons.push_back(ui.b4);
	buttons.push_back(ui.b5);
	buttons.push_back(ui.b6);
	buttons.push_back(ui.b7);
	buttons.push_back(ui.b8);
	buttons.push_back(ui.b9);
}

void joCirclenXapp::initClient(){
	/*QString str("init");
	ui.messageBox->append(str);*/
	if (!alreadyInit){
		if (chooseTeam(team)) {
			ui.messageBox->append("team = " + QString::number(team));
			if (!connected){
				startClient();
			}
			sendTeam(team);
			alreadyInit = true;
			ui.teamLabel->setText(QString::number(team));
		}
	} else {
		QString str("juz wybrales team!");
		ui.messageBox->append(str);
	}

}

bool joCirclenXapp::isNewGame(QString msg){
	
	string str = msg.toStdString().substr(0, 3);
	string str2 = "new";
	if (str.compare(str2) == 0)
		return true;
	else 
		return false;
}

void joCirclenXapp::newGame(){
	ui.messageBox->append("new game");
	ui.teamLabel->setText(QString::number(0));
	ui.moveLabel->setText("0");
	ui.fillLabel->setVisible(false);
	team = 0;
	teamChosen = false;
	alreadyInit = false;;
	playerMoved = false;
	for (int i = 1; i < buttons.size()+1; i++){
		setElement(i, 48);
	}
	fillLCD("000000000");
	//initClient();

}

void joCirclenXapp::setVisibleLabel(){
	if (ui.fillLabel->isVisible()){
		ui.fillLabel->setVisible(false);
	}
	else {
		ui.fillLabel->setVisible(true);
	}
}

void joCirclenXapp::readFromServ() {

	QByteArray temp = clientSock->readAll();
	QString msg(temp);
	ui.messageBox->append("rfs: MSG: " + msg);
	ui.messageBox->append("isNewGame: " + QString::number(isNewGame(msg)));
	
	string afterCheckMsg = checkNewGame(msg);
	string withoutState = getVoteState(QString::fromStdString(afterCheckMsg)); //zwraca pozostala wiadomosc bez stanu gry
	string withoutTurn = getTurn(withoutState); //setturn tez siedzi tu
	//ui.messageBox->append("This -> turn: " + QString::number(this->turn));
	//ui.messageBox->append("Przed getTurn: " + QString::fromStdString(withoutState));
	if (!isNewGame(msg)){
		int turn = withoutState[0] - (int)48;
		//ui.messageBox->append("Current turn: " + QString::number(turn));
		//ui.messageBox->append("This -> turn: " + QString::number(this->turn));
		setTurn(turn);
		
		string withoutGame = getGameState(withoutTurn);
		setGameState(withoutTurn.substr(0, 9));
		ui.messageBox->append(QString::fromStdString(withoutGame));
		if (this->turn == team || turn == 0)
			ui.fillLabel->setVisible(false);
		else if(team != 0)// turn wybrany i rozni sie od naszego wybranego//nawet jak jest 0 - juz nie
			ui.fillLabel->setVisible(true); 
	} else {
		//jesli jest newGame
		showGameOver(); //ktory?
		newGame();
	}
	
	


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
		if (!playerMoved){ // !playerMoved i teamchosen
			QString num = QString::number(intmove);
			QByteArray msgbyte = num.toUtf8();
			clientSock->write(msgbyte);
		} else { //playerMoved i teamchosen
			QString str("juz wykonales ruch!");
			ui.messageBox->append(str);
		}
		
	} else {
		QString str("wybierz team!");
		ui.messageBox->append(str);
	}
}

void joCirclenXapp::setGameState(string game){

	for (int i = 0; i < game.length(); i++){
		setElement(i + 1, game[i]);
	}
}

void joCirclenXapp::showGameOver(){
	QMessageBox::information(this, tr("Koniec gry!"), tr("Wygral gracz nr..."));
}

/* przypisujemy znaki na planszy do glosowania i blokujemy przyciski jak juz zostalo cos tam postawione*/
void joCirclenXapp::setElement(int i, int element){
	int num = element - 48;
	//buttons.[i-1]
	if (buttons.size() > i-1)
		buttons.at(i - 1)->setText(QString::number(num));
	else 
		ui.messageBox->append("przekroczylbym rozmiar wektora! num: " + QString::number(num) 
			+ ", i-1: " + QString::number(i) + ", size: " + QString::number(buttons.size()));
	
	blockButtons();
}

void joCirclenXapp::setTurn(int turn){
	ui.messageBox->append("turn = " + QString::number(turn));
	if (turn == team && team != 0){
		ui.messageBox->append("this->team = " + QString::number(this->turn));
		playerMoved = false;
	}
	this->turn = turn;
}

void joCirclenXapp::setMove1(){
	ui.moveLabel->setText("1");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;

}
void joCirclenXapp::setMove2(){
	//ui.V.moveLabel->setText("1");

	ui.moveLabel->setText("2");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove3(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("3");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove4(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("4");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove5(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("5");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove6(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("6");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove7(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("7");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove8(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("8");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::setMove9(){
	//ui.V.moveLabel->setText("1");
	ui.moveLabel->setText("9");
	sendMove(ui.moveLabel->text());
	if (teamChosen)
		playerMoved = true;
}
void joCirclenXapp::startClient() {

	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &joCirclenXapp::readFromServ);
	string serverIP = ui.serverIP->text().toStdString();
	string serverPort = ui.serverPort->text().toStdString();
	clientSock->connectToHost(QString::fromStdString(serverIP), std::stoi(serverPort));
	connected = true;

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
	this->turn = 0;
	ui.fillLabel->setVisible(false);
	QObject::connect(ui.sendButton, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.team1, SIGNAL(clicked()), this, SLOT(team1()));
	QObject::connect(ui.team1, SIGNAL(clicked()), this, SLOT(initClient()));
	QObject::connect(ui.team2, SIGNAL(clicked()), this, SLOT(team2()));
	QObject::connect(ui.team2, SIGNAL(clicked()), this, SLOT(initClient()));
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(setVisibleLabel()));
	QObject::connect(ui.showmsgbutton, SIGNAL(clicked()), this, SLOT(showGameOver()));
	
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
	initButtons();
}

joCirclenXapp::~joCirclenXapp() { }