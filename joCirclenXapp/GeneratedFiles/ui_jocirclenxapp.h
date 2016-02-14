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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_joCirclenXappClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    QTextEdit *messageBox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *messageEdit;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *joCirclenXappClass)
    {
        if (joCirclenXappClass->objectName().isEmpty())
            joCirclenXappClass->setObjectName(QStringLiteral("joCirclenXappClass"));
        joCirclenXappClass->resize(600, 400);
        centralWidget = new QWidget(joCirclenXappClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(320, 40, 258, 213));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messageLabel = new QLabel(widget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));

        verticalLayout->addWidget(messageLabel);

        messageBox = new QTextEdit(widget);
        messageBox->setObjectName(QStringLiteral("messageBox"));

        verticalLayout->addWidget(messageBox);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 135, 51));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        messageEdit = new QLineEdit(widget1);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));

        verticalLayout_2->addWidget(messageEdit);

        sendButton = new QPushButton(widget1);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        verticalLayout_2->addWidget(sendButton);

        joCirclenXappClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(joCirclenXappClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
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
        sendButton->setText(QApplication::translate("joCirclenXappClass", "Send Message", 0));
    } // retranslateUi

};

namespace Ui {
    class joCirclenXappClass: public Ui_joCirclenXappClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOCIRCLENXAPP_H
