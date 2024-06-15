#include "MainChatWindow.h"
#include "chatWidgeClient.h"
#include "serverwindow.h"
#include "ui_serverwindow.h"

#include <ChatItemWidget.h>

ServerWindow::ServerWindow(ushort port,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerWindow),_port(port)
{
    ui->setupUi(this);
    setupServer();

}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::newClientConnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->listClients->addItem(QString("New Client Added: %1").arg(id));
    auto chatWidget = new ChatWidgeClient(client);
    ui->tabChats->addTab(chatWidget,QString("Client: %1").arg(id));
    // connect(client, &QTcpSocket::readyRead, chatWidget, &ChatItemWidget::readMessage);
}

void ServerWindow::clientDisconnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->listClients->addItem(QString("Client Disconnected %1").arg(id));

}

void ServerWindow::setupServer(){
    _server = new ServerManager(_port);
    connect(_server,&ServerManager::newClientConnected,this,&ServerWindow::newClientConnected);
    connect(_server,&ServerManager::clientDisconnected,this,&ServerWindow::clientDisconnected);
}
