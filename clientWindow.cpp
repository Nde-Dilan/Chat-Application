#include "clientWindow.h"
#include "ui_clientWindow.h"
#include "ClientManager.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setEnabled(false);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_actionConnect_triggered()
{
    _client = new ClientManager();
    connect(_client,&ClientManager::connected,[this]{
            ui->centralwidget->setEnabled(true);
    });
    connect(_client,&ClientManager::disconnected,[this]{
        ui->centralwidget->setEnabled(false);
    });
    connect(_client,&ClientManager::dataReceived,this,&ClientWindow::dataReceived);
    _client->connectToServer();
}

void ClientWindow::dataReceived(QByteArray data)
{
    // ui->lstMessages->addItem(data);
    auto chatWidget = new ChatItemWidget(this);

    chatWidget->setMessage(data);

    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));
    ui->lstMessages->addItem(listItemWidget);

    listItemWidget->setBackground(QColor(67,255,207));

    ui->lstMessages->setItemWidget(listItemWidget,chatWidget);
}


void ClientWindow::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed();

    _client->sendMessage(message);
    // ui->lstMessages->addItem(message);
    ui->lnMessage->setText("");
    auto chatWidget = new ChatItemWidget(this);

    chatWidget->setMessage(message,true);

    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));
    ui->lstMessages->addItem(listItemWidget);

    listItemWidget->setBackground(QColor(187,255,137));

    ui->lstMessages->setItemWidget(listItemWidget,chatWidget);

}


