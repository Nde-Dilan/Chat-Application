#ifndef MAINCHATWINDOW_H
#define MAINCHATWINDOW_H

#include "ClientManager.h"

#include <QMainWindow>

namespace Ui {
class MainChatWindow;
}


#include <QMessageBox>
#include <QDebug>
#include <QCryptographicHash>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QString>
#include <QDateTime>
#include <QVector>
#include <QListWidget>
#include <QVariant>

struct Message {
    QString sender;
    QString content;
    QDateTime timestamp;
    bool isImage; // True if the message is an image
};

struct Conversation {
    QString friendId;
    QString friendName;
    QString friendAvatar;
    QVector<Message> messages;
};

class MainChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainChatWindow(ushort port,int userId=1,QWidget *parent = nullptr);
    ~MainChatWindow();
    bool connectToDatabase();
    bool createTablesIfNotExist();
    QVector<Conversation> loadConversations(int userId);
    void populateChatList(QListWidget* chatList, const QVector<Conversation>& conversations);
    void displayConversation(QListWidget* conversationHistory, const Conversation& conversation);
    void onChatSelected(QListWidget* chatList, QListWidget* conversationHistory, const QVector<Conversation>& conversations);
    void  insertTestData();
    QString getFriendName(int conversationId, int currentUserId);

public slots:
    void readMessage();
    void sendMessage(const QByteArray &message, int recipientId);

private slots:
    void on_sendButton_clicked();
    void onChatItemClicked(QListWidgetItem *item);
    void on_attachButton_clicked();

    void on_userSearch_returnPressed();

    void on_actionConnect_triggered();
    void dataReceived(QByteArray data);

private:
    Ui::MainChatWindow *ui;
     ClientManager *_client;
    ushort _port;
};



#endif // MAINCHATWINDOW_H
