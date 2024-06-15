#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <ClientManager.h>
#include <ChatItemWidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class ClientWindow;
}
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_actionConnect_triggered();
    void dataReceived(QByteArray data);

    void on_btnSend_clicked();

private:
    Ui::ClientWindow *ui;
    ClientManager *_client;
};
#endif // CLIENTWINDOW_H
