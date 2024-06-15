#include "UserChatItemWidget.h"
#include "ui_UserChatItemWidget.h"

UserChatItemWidget::UserChatItemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserChatItemWidget)
{
    ui->setupUi(this);
}

UserChatItemWidget::~UserChatItemWidget()
{
    delete ui;
}


void UserChatItemWidget::setMessage(QString username)
{
    ui->username->setText(username);
}
