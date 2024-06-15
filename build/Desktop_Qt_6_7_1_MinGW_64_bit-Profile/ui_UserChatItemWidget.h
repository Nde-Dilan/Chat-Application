/********************************************************************************
** Form generated from reading UI file 'UserChatItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCHATITEMWIDGET_H
#define UI_USERCHATITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserChatItemWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *profilePicture;
    QLabel *username;

    void setupUi(QWidget *UserChatItemWidget)
    {
        if (UserChatItemWidget->objectName().isEmpty())
            UserChatItemWidget->setObjectName("UserChatItemWidget");
        UserChatItemWidget->resize(400, 58);
        horizontalLayout = new QHBoxLayout(UserChatItemWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        profilePicture = new QLabel(UserChatItemWidget);
        profilePicture->setObjectName("profilePicture");
        profilePicture->setMinimumSize(QSize(40, 40));
        profilePicture->setMaximumSize(QSize(40, 40));
        profilePicture->setStyleSheet(QString::fromUtf8("\n"
"       border-radius: 20px;\n"
"       border: 1px solid #ccc;\n"
"      "));
        profilePicture->setPixmap(QPixmap(QString::fromUtf8(":/icons/user.png")));
        profilePicture->setScaledContents(true);

        horizontalLayout->addWidget(profilePicture);

        username = new QLabel(UserChatItemWidget);
        username->setObjectName("username");
        username->setStyleSheet(QString::fromUtf8("\n"
"       font-size: 14px;\n"
"       padding-left: 10px;\n"
"      "));

        horizontalLayout->addWidget(username);


        retranslateUi(UserChatItemWidget);

        QMetaObject::connectSlotsByName(UserChatItemWidget);
    } // setupUi

    void retranslateUi(QWidget *UserChatItemWidget)
    {
        username->setText(QCoreApplication::translate("UserChatItemWidget", "Username", nullptr));
        (void)UserChatItemWidget;
    } // retranslateUi

};

namespace Ui {
    class UserChatItemWidget: public Ui_UserChatItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCHATITEMWIDGET_H
