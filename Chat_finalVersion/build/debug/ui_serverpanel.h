/********************************************************************************
** Form generated from reading UI file 'serverpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERPANEL_H
#define UI_SERVERPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerPanel
{
public:
    QAction *actionView_available_commands;
    QAction *actionView_Blacklist;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *LogsBrowser;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *typeCommandEdit;
    QPushButton *SendToEveryoneButton;
    QPushButton *SendPrivateButton;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *TypeUserNameEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *searchOptionsButton;
    QPushButton *searchButton;
    QListWidget *UsersList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ServerPanel)
    {
        if (ServerPanel->objectName().isEmpty())
            ServerPanel->setObjectName("ServerPanel");
        ServerPanel->resize(977, 686);
        actionView_available_commands = new QAction(ServerPanel);
        actionView_available_commands->setObjectName("actionView_available_commands");
        actionView_Blacklist = new QAction(ServerPanel);
        actionView_Blacklist->setObjectName("actionView_Blacklist");
        centralwidget = new QWidget(ServerPanel);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        LogsBrowser = new QTextBrowser(centralwidget);
        LogsBrowser->setObjectName("LogsBrowser");
        LogsBrowser->setOpenExternalLinks(true);

        verticalLayout->addWidget(LogsBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        typeCommandEdit = new QLineEdit(centralwidget);
        typeCommandEdit->setObjectName("typeCommandEdit");

        horizontalLayout_2->addWidget(typeCommandEdit);

        SendToEveryoneButton = new QPushButton(centralwidget);
        SendToEveryoneButton->setObjectName("SendToEveryoneButton");

        horizontalLayout_2->addWidget(SendToEveryoneButton);

        SendPrivateButton = new QPushButton(centralwidget);
        SendPrivateButton->setObjectName("SendPrivateButton");

        horizontalLayout_2->addWidget(SendPrivateButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        TypeUserNameEdit = new QLineEdit(centralwidget);
        TypeUserNameEdit->setObjectName("TypeUserNameEdit");

        verticalLayout_2->addWidget(TypeUserNameEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        searchOptionsButton = new QPushButton(centralwidget);
        searchOptionsButton->setObjectName("searchOptionsButton");

        horizontalLayout_3->addWidget(searchOptionsButton);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        horizontalLayout_3->addWidget(searchButton);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        UsersList = new QListWidget(centralwidget);
        UsersList->setObjectName("UsersList");

        verticalLayout_2->addWidget(UsersList);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 7);
        ServerPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ServerPanel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 977, 26));
        ServerPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(ServerPanel);
        statusbar->setObjectName("statusbar");
        ServerPanel->setStatusBar(statusbar);

        retranslateUi(ServerPanel);

        QMetaObject::connectSlotsByName(ServerPanel);
    } // setupUi

    void retranslateUi(QMainWindow *ServerPanel)
    {
        ServerPanel->setWindowTitle(QCoreApplication::translate("ServerPanel", "MainWindow", nullptr));
        actionView_available_commands->setText(QCoreApplication::translate("ServerPanel", "View available commands", nullptr));
        actionView_Blacklist->setText(QCoreApplication::translate("ServerPanel", "View blacklist", nullptr));
        LogsBrowser->setPlaceholderText(QCoreApplication::translate("ServerPanel", "##################Logs are empty#########################", nullptr));
        typeCommandEdit->setPlaceholderText(QCoreApplication::translate("ServerPanel", "Type your message here:", nullptr));
        SendToEveryoneButton->setText(QCoreApplication::translate("ServerPanel", "Send to everyone", nullptr));
        SendPrivateButton->setText(QCoreApplication::translate("ServerPanel", "Send private", nullptr));
        TypeUserNameEdit->setPlaceholderText(QCoreApplication::translate("ServerPanel", "Type user name here:", nullptr));
        searchOptionsButton->setText(QCoreApplication::translate("ServerPanel", "Set search options", nullptr));
        searchButton->setText(QCoreApplication::translate("ServerPanel", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerPanel: public Ui_ServerPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERPANEL_H
