#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <serverManager.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class ServerWindow;
}
QT_END_NAMESPACE

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    ServerWindow(ushort port,QWidget *parent = nullptr);
    ~ServerWindow();

private slots:
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);

private:
    Ui::ServerWindow *ui;
    ServerManager *_server;
    ushort _port;
private: // For methods
    void setupServer();
};
#endif // SERVERWINDOW_H
