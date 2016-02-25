/********************************************************************************
** Form generated from reading UI file 'jocirclenxapp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOCIRCLENXAPP_H
#define UI_JOCIRCLENXAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_joCirclenXappClass
{
public:
    QWidget *centralWidget;
    QTextEdit *messageBox;
    QLabel *messageLabel;
    QLabel *teamLabel;
    QLabel *label_2;
    QPushButton *team2;
    QPushButton *team1;
    QLabel *label;
    QPushButton *sendButton;
    QLineEdit *messageEdit;
    QLabel *moveLabel;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lcd1;
    QLabel *lcd2;
    QLabel *lcd3;
    QLabel *lcd4;
    QLabel *lcd5;
    QLabel *lcd6;
    QLabel *lcd7;
    QLabel *lcd8;
    QLabel *lcd9;
    QLabel *fillLabel;
    QPushButton *pushButton;
    QPushButton *showmsgbutton;
    QLineEdit *serverIP;
    QLineEdit *serverPort;
    QPushButton *b3;
    QPushButton *b2;
    QPushButton *b1;
    QPushButton *b6;
    QPushButton *b4;
    QPushButton *b5;
    QPushButton *b9;
    QPushButton *b7;
    QPushButton *b8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *joCirclenXappClass)
    {
        if (joCirclenXappClass->objectName().isEmpty())
            joCirclenXappClass->setObjectName(QStringLiteral("joCirclenXappClass"));
        joCirclenXappClass->resize(578, 556);
        centralWidget = new QWidget(joCirclenXappClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        messageBox = new QTextEdit(centralWidget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setGeometry(QRect(30, 380, 221, 101));
        messageLabel = new QLabel(centralWidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(30, 360, 256, 13));
        teamLabel = new QLabel(centralWidget);
        teamLabel->setObjectName(QStringLiteral("teamLabel"));
        teamLabel->setGeometry(QRect(20, 83, 91, 46));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        teamLabel->setFont(font);
        teamLabel->setCursor(QCursor(Qt::WhatsThisCursor));
        teamLabel->setAutoFillBackground(false);
        teamLabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 91, 47));
        team2 = new QPushButton(centralWidget);
        team2->setObjectName(QStringLiteral("team2"));
        team2->setGeometry(QRect(230, 70, 91, 51));
        team1 = new QPushButton(centralWidget);
        team1->setObjectName(QStringLiteral("team1"));
        team1->setGeometry(QRect(130, 70, 91, 51));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 50, 191, 21));
        label->setAlignment(Qt::AlignCenter);
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(350, 170, 221, 23));
        messageEdit = new QLineEdit(centralWidget);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        messageEdit->setGeometry(QRect(350, 140, 221, 20));
        moveLabel = new QLabel(centralWidget);
        moveLabel->setObjectName(QStringLiteral("moveLabel"));
        moveLabel->setGeometry(QRect(30, 320, 72, 20));
        moveLabel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 290, 72, 32));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 140, 81, 16));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 120, 201, 16));
        label_5->setAlignment(Qt::AlignCenter);
        lcd1 = new QLabel(centralWidget);
        lcd1->setObjectName(QStringLiteral("lcd1"));
        lcd1->setGeometry(QRect(10, 160, 31, 31));
        lcd1->setAlignment(Qt::AlignCenter);
        lcd2 = new QLabel(centralWidget);
        lcd2->setObjectName(QStringLiteral("lcd2"));
        lcd2->setGeometry(QRect(50, 160, 31, 31));
        lcd2->setAlignment(Qt::AlignCenter);
        lcd3 = new QLabel(centralWidget);
        lcd3->setObjectName(QStringLiteral("lcd3"));
        lcd3->setGeometry(QRect(90, 160, 31, 31));
        lcd3->setAlignment(Qt::AlignCenter);
        lcd4 = new QLabel(centralWidget);
        lcd4->setObjectName(QStringLiteral("lcd4"));
        lcd4->setGeometry(QRect(10, 200, 31, 31));
        lcd4->setAlignment(Qt::AlignCenter);
        lcd5 = new QLabel(centralWidget);
        lcd5->setObjectName(QStringLiteral("lcd5"));
        lcd5->setGeometry(QRect(50, 200, 31, 31));
        lcd5->setAlignment(Qt::AlignCenter);
        lcd6 = new QLabel(centralWidget);
        lcd6->setObjectName(QStringLiteral("lcd6"));
        lcd6->setGeometry(QRect(90, 200, 31, 31));
        lcd6->setAlignment(Qt::AlignCenter);
        lcd7 = new QLabel(centralWidget);
        lcd7->setObjectName(QStringLiteral("lcd7"));
        lcd7->setGeometry(QRect(10, 240, 31, 31));
        lcd7->setAlignment(Qt::AlignCenter);
        lcd8 = new QLabel(centralWidget);
        lcd8->setObjectName(QStringLiteral("lcd8"));
        lcd8->setGeometry(QRect(50, 240, 31, 31));
        lcd8->setAlignment(Qt::AlignCenter);
        lcd9 = new QLabel(centralWidget);
        lcd9->setObjectName(QStringLiteral("lcd9"));
        lcd9->setGeometry(QRect(90, 240, 31, 31));
        lcd9->setAlignment(Qt::AlignCenter);
        fillLabel = new QLabel(centralWidget);
        fillLabel->setObjectName(QStringLiteral("fillLabel"));
        fillLabel->setEnabled(true);
        fillLabel->setGeometry(QRect(120, 20, 361, 101));
        fillLabel->setAutoFillBackground(true);
        fillLabel->setFrameShape(QFrame::Box);
        fillLabel->setFrameShadow(QFrame::Plain);
        fillLabel->setAlignment(Qt::AlignCenter);
        fillLabel->setWordWrap(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 200, 75, 23));
        showmsgbutton = new QPushButton(centralWidget);
        showmsgbutton->setObjectName(QStringLiteral("showmsgbutton"));
        showmsgbutton->setGeometry(QRect(350, 200, 75, 23));
        serverIP = new QLineEdit(centralWidget);
        serverIP->setObjectName(QStringLiteral("serverIP"));
        serverIP->setGeometry(QRect(30, 20, 141, 20));
        serverPort = new QLineEdit(centralWidget);
        serverPort->setObjectName(QStringLiteral("serverPort"));
        serverPort->setGeometry(QRect(180, 20, 141, 20));
        b3 = new QPushButton(centralWidget);
        b3->setObjectName(QStringLiteral("b3"));
        b3->setGeometry(QRect(270, 140, 61, 61));
        b2 = new QPushButton(centralWidget);
        b2->setObjectName(QStringLiteral("b2"));
        b2->setGeometry(QRect(200, 140, 61, 61));
        b1 = new QPushButton(centralWidget);
        b1->setObjectName(QStringLiteral("b1"));
        b1->setGeometry(QRect(130, 140, 61, 61));
        b6 = new QPushButton(centralWidget);
        b6->setObjectName(QStringLiteral("b6"));
        b6->setGeometry(QRect(270, 210, 61, 61));
        b4 = new QPushButton(centralWidget);
        b4->setObjectName(QStringLiteral("b4"));
        b4->setGeometry(QRect(131, 210, 61, 61));
        b5 = new QPushButton(centralWidget);
        b5->setObjectName(QStringLiteral("b5"));
        b5->setGeometry(QRect(200, 210, 61, 61));
        b9 = new QPushButton(centralWidget);
        b9->setObjectName(QStringLiteral("b9"));
        b9->setGeometry(QRect(270, 280, 61, 61));
        b7 = new QPushButton(centralWidget);
        b7->setObjectName(QStringLiteral("b7"));
        b7->setGeometry(QRect(130, 280, 61, 61));
        b8 = new QPushButton(centralWidget);
        b8->setObjectName(QStringLiteral("b8"));
        b8->setGeometry(QRect(200, 280, 61, 61));
        joCirclenXappClass->setCentralWidget(centralWidget);
        messageBox->raise();
        messageLabel->raise();
        teamLabel->raise();
        label_2->raise();
        team2->raise();
        team1->raise();
        label->raise();
        sendButton->raise();
        messageEdit->raise();
        moveLabel->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        lcd1->raise();
        lcd2->raise();
        lcd3->raise();
        lcd4->raise();
        lcd5->raise();
        lcd6->raise();
        lcd7->raise();
        lcd8->raise();
        lcd9->raise();
        pushButton->raise();
        showmsgbutton->raise();
        serverIP->raise();
        serverPort->raise();
        b3->raise();
        b2->raise();
        b1->raise();
        b6->raise();
        b4->raise();
        b5->raise();
        b9->raise();
        b7->raise();
        b8->raise();
        fillLabel->raise();
        menuBar = new QMenuBar(joCirclenXappClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 21));
        joCirclenXappClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(joCirclenXappClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        joCirclenXappClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(joCirclenXappClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        joCirclenXappClass->setStatusBar(statusBar);

        retranslateUi(joCirclenXappClass);

        QMetaObject::connectSlotsByName(joCirclenXappClass);
    } // setupUi

    void retranslateUi(QMainWindow *joCirclenXappClass)
    {
        joCirclenXappClass->setWindowTitle(QApplication::translate("joCirclenXappClass", "joCirclenXapp", 0));
        messageLabel->setText(QApplication::translate("joCirclenXappClass", "Message From Server:", 0));
        teamLabel->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        label_2->setText(QApplication::translate("joCirclenXappClass", "DRU\305\273YNA GRACZA", 0));
        team2->setText(QApplication::translate("joCirclenXappClass", "O", 0));
        team1->setText(QApplication::translate("joCirclenXappClass", "X", 0));
        label->setText(QApplication::translate("joCirclenXappClass", "Do\305\202\304\205cz do dru\305\274yny", 0));
        sendButton->setText(QApplication::translate("joCirclenXappClass", "Send Message", 0));
        moveLabel->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        label_3->setText(QApplication::translate("joCirclenXappClass", "Wybrany ruch:", 0));
        label_4->setText(QApplication::translate("joCirclenXappClass", "Liczba g\305\202os\303\263w:", 0));
        label_5->setText(QApplication::translate("joCirclenXappClass", "G\305\202osuj na ruch", 0));
        lcd1->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd2->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd3->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd4->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd5->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd6->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd7->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd8->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        lcd9->setText(QApplication::translate("joCirclenXappClass", "0", 0));
        fillLabel->setText(QApplication::translate("joCirclenXappClass", "Kolej dru\305\274yny przeciwnej", 0));
        pushButton->setText(QApplication::translate("joCirclenXappClass", "Visible", 0));
        showmsgbutton->setText(QApplication::translate("joCirclenXappClass", "show msg", 0));
        serverIP->setText(QApplication::translate("joCirclenXappClass", "localhost", 0));
        serverPort->setText(QApplication::translate("joCirclenXappClass", "1111", 0));
        b3->setText(QString());
        b2->setText(QString());
        b1->setText(QString());
        b6->setText(QString());
        b4->setText(QString());
        b5->setText(QString());
        b9->setText(QString());
        b7->setText(QString());
        b8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class joCirclenXappClass: public Ui_joCirclenXappClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOCIRCLENXAPP_H
