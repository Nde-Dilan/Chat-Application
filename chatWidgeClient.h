#ifndef CHATWIDGECLIENT_H
#define CHATWIDGECLIENT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ChatWidgeClient;
}

class ChatWidgeClient : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidgeClient(QTcpSocket *client,QWidget *parent = nullptr);
    ~ChatWidgeClient();

private slots:
    void dataReceived();

    void on_btnSend_clicked();
    void clientDisconnected();

    void on_lnMessage_editingFinished();

private:
    Ui::ChatWidgeClient *ui;
    QTcpSocket *_client;
};

#endif // CHATWIDGECLIENT_H
