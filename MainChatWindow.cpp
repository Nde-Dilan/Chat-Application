#include "ChatItemWidget.h"
#include "ClientManager.h"
#include "MainChatWindow.h"
#include "UserChatItemWidget.h"
#include "ui_MainChatWindow.h"
#include <QDataStream>

MainChatWindow::MainChatWindow(ushort port ,int userId,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainChatWindow),_port(port)
{
    ui->setupUi(this);

    ui->composer->setDisabled(true);


    // Connect the itemClicked signal of the chatList to the onChatItemClicked slot
    connect(ui->chatList, &QListWidget::itemClicked, this, &MainChatWindow::onChatItemClicked);


     insertTestData();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QtProjects/ChatApplication/LoginApplication/chat.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }

    // createTablesIfNotExist();
    QVector<Conversation> conversations= loadConversations(1);
    populateChatList(ui->chatList,conversations);
    //displayConversation();
}

MainChatWindow::~MainChatWindow()
{
    delete ui;
}


void MainChatWindow::insertTestData() {
    QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/QtProjects/ChatApplication/LoginApplication/chat.db");
    db.open();
    if(!db.isOpen()){
        qDebug() << "Failed to open the database";
    }
    QSqlQuery query;

    QStringList insertUsers = {
        "INSERT INTO users (id, name, avatar) VALUES (2, 'Dilan', 'icons/user.png');",
        "INSERT INTO users (id, name, avatar) VALUES (3, 'David', 'icons/user.png');",
        "INSERT INTO users (id, name, avatar) VALUES (4, 'Jonh', 'icons/user.png');",
        "INSERT INTO users (id, name, avatar) VALUES (5, 'Marie', 'icons/user.png');",
        "INSERT INTO users (id, name, avatar) VALUES (6, 'Lysa', 'icons/user.png');"
    };

    QStringList insertConversations = {
        "INSERT INTO conversations (id, user_id, friend_id) VALUES (1, 1, 2);",
        "INSERT INTO conversations (id, user_id, friend_id) VALUES (2, 1, 3);",
        "INSERT INTO conversations (id, user_id, friend_id) VALUES (3, 1, 4);",
        "INSERT INTO conversations (id, user_id, friend_id) VALUES (4, 1, 5);",
        "INSERT INTO conversations (id, user_id, friend_id) VALUES (5, 1, 6);"
    };

    QStringList insertMessages = {
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (1, 1, 'Hello User2!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (1, 2, 'Hi User1!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (2, 1, 'Hello User3!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (2, 3, 'Hi User1!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (3, 1, 'Hello User4!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (3, 4, 'Hi User1!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (4, 1, 'Hello User5!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (4, 5, 'Hi User1!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (5, 1, 'Hello User6!', 0);",
        "INSERT INTO messages (conversation_id, sender_id, content, is_image) VALUES (5, 6, 'Hi User1!', 0);"
    };

    foreach (const QString &queryStr, insertUsers) {
        if (!query.exec(queryStr)) {
            qDebug() << "Error inserting user:" << query.lastError().text();
        }
    }

    foreach (const QString &queryStr, insertConversations) {
        if (!query.exec(queryStr)) {
            qDebug() << "Error inserting conversation:" << query.lastError().text();
        }
    }

    foreach (const QString &queryStr, insertMessages) {
        if (!query.exec(queryStr)) {
            qDebug() << "Error inserting message:" << query.lastError().text();
        }
    }
}
bool MainChatWindow::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QtProjects/ChatApplication/LoginApplication/chat.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return false;
    } else {
        qDebug() << "Database: connection ok";
        return true;
    }
}

bool MainChatWindow::createTablesIfNotExist()
{
    QSqlQuery query;

    QString createUsersTable = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            avatar TEXT
        );
    )";

    QString createConversationsTable = R"(
        CREATE TABLE IF NOT EXISTS conversations (
            id INTEGER PRIMARY KEY,
            user_id INTEGER NOT NULL,
            friend_id INTEGER NOT NULL,
            FOREIGN KEY (user_id) REFERENCES users(id),
            FOREIGN KEY (friend_id) REFERENCES users(id)
        );
    )";

    QString createMessagesTable = R"(
        CREATE TABLE IF NOT EXISTS messages (
            id INTEGER PRIMARY KEY,
            conversation_id INTEGER NOT NULL,
            sender_id INTEGER NOT NULL,
            content TEXT NOT NULL,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
            is_image BOOLEAN DEFAULT 0,
            FOREIGN KEY (conversation_id) REFERENCES conversations(id),
            FOREIGN KEY (sender_id) REFERENCES users(id)
        );
    )";

    if (!query.exec(createUsersTable)) {
        qDebug() << "Couldn't create the table 'users': one might already exist.";
        return false;
    }

    if (!query.exec(createConversationsTable)) {
        qDebug() << "Couldn't create the table 'conversations': one might already exist.";
        return false;
    }

    if (!query.exec(createMessagesTable)) {
        qDebug() << "Couldn't create the table 'messages': one might already exist.";
        return false;
    }

    return true;
}

QVector<Conversation> MainChatWindow::loadConversations(int userId) {
    QVector<Conversation> conversations;

    QSqlQuery query;
    query.prepare(R"(
        SELECT c.id, u.name, u.avatar
        FROM conversations c
        JOIN users u ON u.id = c.friend_id
        WHERE c.user_id = :userId;
    )");
    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            Conversation conversation;
            conversation.friendId = query.value(0).toString();
            conversation.friendName = query.value(1).toString();
            conversation.friendAvatar = query.value(2).toString();

            // Load messages for this conversation
            QSqlQuery messageQuery;
            messageQuery.prepare(R"(
                SELECT sender_id, content, timestamp, is_image
                FROM messages
                WHERE conversation_id = :conversationId;
            )");
            messageQuery.bindValue(":conversationId", conversation.friendId);

            if (messageQuery.exec()) {
                while (messageQuery.next()) {
                    Message message;
                    message.sender = messageQuery.value(0).toString();
                    message.content = messageQuery.value(1).toString();
                    message.timestamp = messageQuery.value(2).toDateTime();
                    message.isImage = messageQuery.value(3).toBool();
                    conversation.messages.append(message);
                }
            }
            conversations.append(conversation);
        }
    }

    return conversations;
}

void MainChatWindow::populateChatList(QListWidget* chatList, const QVector<Conversation>& conversations) {
    chatList->clear();
    for (const auto& conversation : conversations) {



        auto chatWidget = new UserChatItemWidget(this);

        chatWidget->setMessage(conversation.friendName);


        QListWidgetItem* item = new QListWidgetItem(chatList);
        item->setSizeHint(QSize(0,65));
        ui->chatList->addItem(item);
        item->setText(conversation.friendName);
        ui->chatList->setItemWidget(item,chatWidget);


    }
}

void MainChatWindow::displayConversation(QListWidget* conversationHistory, const Conversation& conversation) {
    conversationHistory->clear();
    for (const auto& message : conversation.messages) {
        QListWidgetItem* item = new QListWidgetItem(conversationHistory);
        item->setText(message.content);
        conversationHistory->addItem(item);
    }
}

void MainChatWindow::onChatSelected(QListWidget* chatList, QListWidget* conversationHistory, const QVector<Conversation>& conversations) {
    QObject::connect(chatList, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
        QString friendId = item->data(Qt::UserRole).toString();
        for (const auto& conversation : conversations) {
            if (conversation.friendId == friendId) {
                displayConversation(conversationHistory, conversation);
                break;
            }
        }
    });
}

void MainChatWindow::on_sendButton_clicked()
{

    auto message = ui->messageInput->text().trimmed();
    // Validate for empty fields
    if (message.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "Please enter a message before sending and make sure you're connected.");
        return;
    }
    _client->sendMessage(message);

    ui->messageInput->setText("");
    auto chatWidget = new ChatItemWidget(this);

    chatWidget->setMessage(message,true);

    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));

    ui->conversationHistory->addItem(listItemWidget);

    listItemWidget->setBackground(QColor(187,255,137));

    ui->conversationHistory->setItemWidget(listItemWidget,chatWidget);
}

void MainChatWindow::onChatItemClicked(QListWidgetItem *item)
{
    // Handle the chat item click event

    QString username = item->text();
    /**
    *TODO: Optimize the displayConversation, so that it loads the history of a particular user with its
    *particular conversation, since we already have a messageItem widget just load it to the chat history for
    *each item found inside the conversation.
    *Do it for all users to permit a smooth and non breaking navigation.
    */

    /**
    *TODO: Refactor the client code and incorporate it here to make different client to connect and interchange
    *messages for now (maybe images after), and conclude with the chat part.
    *
    */

    /**
     * Add the send Email functionality on the registration page, and alter the user table to add another
     * Key that will help in user searching(their unique identifyer) and Implement 	Add friends using unique ID search
     * Friend request (have a look at the repo insidecomputal labs
     * */

    /**
     *
     * */

    // displayConversation(ui->conversationHistory,);

    // Call a specific function with the username
    // Example:
    qDebug() << "Chat item clicked: " << username;
}


void MainChatWindow::on_attachButton_clicked()
{

}


void MainChatWindow::on_userSearch_returnPressed()
{
    //Implement search here
}


void MainChatWindow::readMessage()
{
    auto socket = _client->getSocket();
    QDataStream in(socket);
    int senderId=0;
    QByteArray payload;

    in >> senderId >> payload;

    QString message = QString("From Client %1: \n %2").arg(senderId).arg(QString::fromUtf8(payload));

    ui->messageInput->setText("");
    auto chatWidget = new ChatItemWidget(this);

    chatWidget->setMessage(message,true);

    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));

    ui->conversationHistory->addItem(listItemWidget);

    listItemWidget->setBackground(QColor(187,255,137));

    ui->conversationHistory->setItemWidget(listItemWidget,chatWidget);

}

void MainChatWindow::sendMessage(const QByteArray &message, int recipientId)
{
    auto socket = _client->getSocket();
    QDataStream out(socket);
    out << recipientId << message;
}



void MainChatWindow::on_actionConnect_triggered()
{
    _client = new ClientManager(QHostAddress::LocalHost,_port);
    connect(_client,&ClientManager::connected,[this]{
        ui->composer->setEnabled(true);
    });
    connect(_client,&ClientManager::disconnected,[this]{
        ui->composer->setEnabled(false);
    });
    connect(_client,&ClientManager::dataReceived,this,&MainChatWindow::dataReceived);
    _client->connectToServer();
}

void MainChatWindow::dataReceived(QByteArray data)
{
    // ui->lstMessages->addItem(data);
    auto chatWidget = new ChatItemWidget(this);

    chatWidget->setMessage(data);

    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));

    ui->conversationHistory->addItem(listItemWidget);

    listItemWidget->setBackground(QColor(67,255,207));

    ui->conversationHistory->setItemWidget(listItemWidget,chatWidget);
}

