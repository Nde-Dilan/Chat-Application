/********************************************************************************
** Form generated from reading UI file 'chatWidgeClient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGECLIENT_H
#define UI_CHATWIDGECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidgeClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listMessages;
    QWidget *wdgSend;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lnMessage;
    QPushButton *btnSend;

    void setupUi(QWidget *ChatWidgeClient)
    {
        if (ChatWidgeClient->objectName().isEmpty())
            ChatWidgeClient->setObjectName("ChatWidgeClient");
        ChatWidgeClient->resize(418, 313);
        verticalLayout_2 = new QVBoxLayout(ChatWidgeClient);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        listMessages = new QListWidget(ChatWidgeClient);
        listMessages->setObjectName("listMessages");

        verticalLayout->addWidget(listMessages);

        wdgSend = new QWidget(ChatWidgeClient);
        wdgSend->setObjectName("wdgSend");
        horizontalLayout = new QHBoxLayout(wdgSend);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(wdgSend);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lnMessage = new QLineEdit(wdgSend);
        lnMessage->setObjectName("lnMessage");

        horizontalLayout->addWidget(lnMessage);

        btnSend = new QPushButton(wdgSend);
        btnSend->setObjectName("btnSend");

        horizontalLayout->addWidget(btnSend);

        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addWidget(wdgSend);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ChatWidgeClient);

        QMetaObject::connectSlotsByName(ChatWidgeClient);
    } // setupUi

    void retranslateUi(QWidget *ChatWidgeClient)
    {
        ChatWidgeClient->setWindowTitle(QCoreApplication::translate("ChatWidgeClient", "Form", nullptr));
        label->setText(QCoreApplication::translate("ChatWidgeClient", "Message", nullptr));
        lnMessage->setText(QString());
        btnSend->setText(QCoreApplication::translate("ChatWidgeClient", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidgeClient: public Ui_ChatWidgeClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGECLIENT_H
