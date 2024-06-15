/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QPushButton *registerBtn;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label;
    QPushButton *logBtn;
    QLineEdit *password;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(730, 486);
        LoginWindow->setMinimumSize(QSize(730, 486));
        LoginWindow->setMaximumSize(QSize(730, 486));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/users.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white;\n"
"font-weight:bold;"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 20, 641, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Ink Free")});
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:white;"));
        registerBtn = new QPushButton(centralwidget);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setGeometry(QRect(410, 350, 151, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        registerBtn->setFont(font1);
        registerBtn->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;\n"
"border:1px solid aqua;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 190, 101, 31));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:white;"));
        username = new QLineEdit(centralwidget);
        username->setObjectName("username");
        username->setGeometry(QRect(420, 80, 161, 31));
        username->setStyleSheet(QString::fromUtf8("color:white;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 80, 101, 31));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        logBtn = new QPushButton(centralwidget);
        logBtn->setObjectName("logBtn");
        logBtn->setGeometry(QRect(140, 350, 121, 41));
        logBtn->setFont(font1);
        logBtn->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;\n"
"border:1px solid aqua;"));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(420, 190, 161, 31));
        password->setStyleSheet(QString::fromUtf8("color:white;"));
        password->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 60, 231, 221));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/ictu-black.jpeg")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 420, 201, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Impact")});
        font2.setPointSize(12);
        font2.setBold(true);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0);"));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 20));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login Page -[Chat App]", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "DJOUELA SIGNE MARIE ROSINE", nullptr));
        registerBtn->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        logBtn->setText(QCoreApplication::translate("LoginWindow", "Sign In", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("LoginWindow", "\302\251 2024 , By Your Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
