#include "chatWidgeClient.h"
#include "ui_chatWidgeClient.h"

ChatWidgeClient::ChatWidgeClient(QTcpSocket *client,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatWidgeClient),
    _client(client)
{
    ui->setupUi(this);

    //Connect to a slot
    connect(_client,&QTcpSocket::readyRead,this,&ChatWidgeClient::dataReceived);
    connect(_client,&QTcpSocket::disconnected,this,&ChatWidgeClient::clientDisconnected);
}

ChatWidgeClient::~ChatWidgeClient()
{
    delete ui;
}

void ChatWidgeClient::dataReceived()
{
    auto data = _client->readAll();
    qDebug()<< "Printing data";
    qDebug()<< data ;
    ui->listMessages->addItem(data);
}

void ChatWidgeClient::on_btnSend_clicked()
{
    _client->write(ui->lnMessage->text().trimmed().toUtf8());
    qDebug()<< "Printing sent message";
    qDebug() << ui->lnMessage->text() ;
    ui->listMessages->addItem(ui->lnMessage->text().trimmed().toUtf8());
    ui->lnMessage->setText("");
}

void ChatWidgeClient::clientDisconnected()
{
    ui->wdgSend->setEnabled(false);
}


void ChatWidgeClient::on_lnMessage_editingFinished()
{
    _client->write(ui->lnMessage->text().trimmed().toUtf8());
    ui->lnMessage->setText("");
}

