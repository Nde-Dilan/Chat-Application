/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QPushButton *logInBtn;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label;
    QPushButton *regBtn;
    QLineEdit *password;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *email;
    QLineEdit *confirm_password;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(730, 486);
        RegisterWindow->setMinimumSize(QSize(730, 486));
        RegisterWindow->setMaximumSize(QSize(730, 486));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/users.png"), QSize(), QIcon::Normal, QIcon::Off);
        RegisterWindow->setWindowIcon(icon);
        RegisterWindow->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:black;"));
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName("centralwidget");
        logInBtn = new QPushButton(centralwidget);
        logInBtn->setObjectName("logInBtn");
        logInBtn->setGeometry(QRect(400, 350, 151, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        logInBtn->setFont(font);
        logInBtn->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;\n"
"border:1px solid aqua;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 180, 101, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:white;"));
        username = new QLineEdit(centralwidget);
        username->setObjectName("username");
        username->setGeometry(QRect(420, 70, 161, 31));
        username->setStyleSheet(QString::fromUtf8("color:white;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 70, 101, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        regBtn = new QPushButton(centralwidget);
        regBtn->setObjectName("regBtn");
        regBtn->setGeometry(QRect(140, 350, 121, 41));
        regBtn->setFont(font);
        regBtn->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;\n"
"border:1px solid aqua;"));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(430, 180, 161, 31));
        password->setStyleSheet(QString::fromUtf8("color:white;"));
        password->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 70, 231, 221));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/ictu-black.jpeg")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 420, 201, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Impact")});
        font1.setPointSize(12);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color:black;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 120, 101, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color:white;"));
        email = new QLineEdit(centralwidget);
        email->setObjectName("email");
        email->setGeometry(QRect(420, 120, 161, 31));
        email->setStyleSheet(QString::fromUtf8("color:white;"));
        confirm_password = new QLineEdit(centralwidget);
        confirm_password->setObjectName("confirm_password");
        confirm_password->setGeometry(QRect(490, 240, 161, 31));
        confirm_password->setStyleSheet(QString::fromUtf8("color:white;"));
        confirm_password->setEchoMode(QLineEdit::Password);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(300, 240, 171, 31));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color:white;"));
        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 21));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName("statusbar");
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Registration Page -[Chat App]", nullptr));
        logInBtn->setText(QCoreApplication::translate("RegisterWindow", "Sign In", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "Username", nullptr));
        regBtn->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("RegisterWindow", "\302\251 2023 , By NDE HURICH DILAN", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterWindow", "Email", nullptr));
        label_7->setText(QCoreApplication::translate("RegisterWindow", "Confirm Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
