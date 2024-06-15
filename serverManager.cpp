#include "ServerManager.h"

ServerManager::ServerManager(ushort port,QObject *parent)
    : QObject{parent},_clientIdCounter(0)
{
    setupServer(port);
}

void ServerManager::newClientConnectionReceived(){
    //Receive connection from the server
    auto client = _server->nextPendingConnection();

    client->setProperty("id", ++_clientIdCounter);
    _clients[_clientIdCounter] = client;


    connect(client, &QTcpSocket::disconnected, this, [this, client]() {
        clientDisconnected(client);
    });

    connect(client, &QTcpSocket::readyRead, this, &ServerManager::readClientData);

    emit newClientConnected(client);
}

void ServerManager::onClientDisconnected(){

    auto client = qobject_cast<QTcpSocket*>(sender());
    int id = client->property("id").toInt();

    _clients.remove(id);
    client->deleteLater();

    //Notify the program that a client disconnected
    emit clientDisconnected(client);

}

void ServerManager::readClientData()
{
    auto client = qobject_cast<QTcpSocket*>(sender());
    QByteArray message = client->readAll();

    handleClientMessage(client, message);
}

void ServerManager::handleClientMessage(QTcpSocket *client, const QByteArray &message)
{
    QDataStream in(message);
    int recipientId;
    QByteArray payload;

    in >> recipientId >> payload;

    if (_clients.contains(recipientId)) {
        auto recipient = _clients[recipientId];
        QDataStream out(recipient);
        out << client->property("id").toInt() << payload;
    }
}

void ServerManager::setupServer(ushort port){
    _server = new QTcpServer(this);
    connect(_server,&QTcpServer::newConnection, this,&ServerManager::newClientConnectionReceived);
    _server->listen(QHostAddress::Any,port );
}

