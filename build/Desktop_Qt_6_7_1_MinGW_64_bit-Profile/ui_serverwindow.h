/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *grpChats;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabChats;
    QGroupBox *grpClients;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listClients;
    QPushButton *btnDisconnectAll;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName("ServerWindow");
        ServerWindow->resize(800, 350);
        centralwidget = new QWidget(ServerWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 9);
        grpChats = new QGroupBox(centralwidget);
        grpChats->setObjectName("grpChats");
        verticalLayout = new QVBoxLayout(grpChats);
        verticalLayout->setObjectName("verticalLayout");
        tabChats = new QTabWidget(grpChats);
        tabChats->setObjectName("tabChats");

        verticalLayout->addWidget(tabChats);


        horizontalLayout->addWidget(grpChats);

        grpClients = new QGroupBox(centralwidget);
        grpClients->setObjectName("grpClients");
        verticalLayout_2 = new QVBoxLayout(grpClients);
        verticalLayout_2->setObjectName("verticalLayout_2");
        listClients = new QListWidget(grpClients);
        listClients->setObjectName("listClients");

        verticalLayout_2->addWidget(listClients);

        btnDisconnectAll = new QPushButton(grpClients);
        btnDisconnectAll->setObjectName("btnDisconnectAll");

        verticalLayout_2->addWidget(btnDisconnectAll);


        horizontalLayout->addWidget(grpClients);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        ServerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ServerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ServerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ServerWindow);
        statusbar->setObjectName("statusbar");
        ServerWindow->setStatusBar(statusbar);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QCoreApplication::translate("ServerWindow", "Server", nullptr));
        grpChats->setTitle(QCoreApplication::translate("ServerWindow", "GroupBox", nullptr));
        grpClients->setTitle(QCoreApplication::translate("ServerWindow", "Clients", nullptr));
        btnDisconnectAll->setText(QCoreApplication::translate("ServerWindow", "Disconnect All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
