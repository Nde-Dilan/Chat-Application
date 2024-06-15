#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500, QObject *parent = nullptr);

private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();
     void readClientData();
signals:
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);
private: // For fields
    QTcpServer *_server;
    // QList<QTcpSocket *> _clients;
    QMap<int, QTcpSocket*> _clients; // Map to store clients by their IDs
    int _clientIdCounter;

    void handleClientMessage(QTcpSocket *client, const QByteArray &message);


private: // For the methods
    void setupServer(ushort port);
};

#endif // SERVERMANAGER_H
