/********************************************************************************
** Form generated from reading UI file 'ChatItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATITEMWIDGET_H
#define UI_CHATITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatItemWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTime;
    QLabel *lblMessage;

    void setupUi(QWidget *ChatItemWidget)
    {
        if (ChatItemWidget->objectName().isEmpty())
            ChatItemWidget->setObjectName("ChatItemWidget");
        ChatItemWidget->resize(400, 91);
        verticalLayout = new QVBoxLayout(ChatItemWidget);
        verticalLayout->setObjectName("verticalLayout");
        lblTime = new QLabel(ChatItemWidget);
        lblTime->setObjectName("lblTime");

        verticalLayout->addWidget(lblTime);

        lblMessage = new QLabel(ChatItemWidget);
        lblMessage->setObjectName("lblMessage");

        verticalLayout->addWidget(lblMessage, 0, Qt::AlignRight);


        retranslateUi(ChatItemWidget);

        QMetaObject::connectSlotsByName(ChatItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatItemWidget)
    {
        ChatItemWidget->setWindowTitle(QCoreApplication::translate("ChatItemWidget", "Form", nullptr));
        lblTime->setText(QCoreApplication::translate("ChatItemWidget", "Message", nullptr));
        lblMessage->setText(QCoreApplication::translate("ChatItemWidget", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatItemWidget: public Ui_ChatItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATITEMWIDGET_H
