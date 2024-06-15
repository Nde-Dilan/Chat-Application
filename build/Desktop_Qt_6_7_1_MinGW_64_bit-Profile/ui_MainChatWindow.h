/********************************************************************************
** Form generated from reading UI file 'MainChatWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCHATWINDOW_H
#define UI_MAINCHATWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainChatWindow
{
public:
    QAction *actionConnect;
    QAction *actionExit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftSection;
    QVBoxLayout *leftLayout;
    QLineEdit *userSearch;
    QListWidget *chatList;
    QWidget *rightSection;
    QVBoxLayout *rightLayout;
    QWidget *header;
    QHBoxLayout *headerLayout;
    QLabel *contactName;
    QListWidget *conversationHistory;
    QWidget *composer;
    QHBoxLayout *composerLayout;
    QLineEdit *messageInput;
    QPushButton *attachButton;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainChatWindow)
    {
        if (MainChatWindow->objectName().isEmpty())
            MainChatWindow->setObjectName("MainChatWindow");
        MainChatWindow->resize(800, 600);
        MainChatWindow->setMaximumSize(QSize(800, 600));
        actionConnect = new QAction(MainChatWindow);
        actionConnect->setObjectName("actionConnect");
        actionExit = new QAction(MainChatWindow);
        actionExit->setObjectName("actionExit");
        layoutWidget = new QWidget(MainChatWindow);
        layoutWidget->setObjectName("layoutWidget");
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        leftSection = new QWidget(layoutWidget);
        leftSection->setObjectName("leftSection");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftSection->sizePolicy().hasHeightForWidth());
        leftSection->setSizePolicy(sizePolicy);
        leftSection->setStyleSheet(QString::fromUtf8("\n"
"       QWidget#leftSection {\n"
"           background-color: #f0f0f0;\n"
"           border-right: 1px solid #dcdcdc;\n"
"       }\n"
"       QListWidget#chatList {\n"
"           font-size: 14px;\n"
"           padding: 5px;\n"
"       }\n"
"      "));
        leftLayout = new QVBoxLayout(leftSection);
        leftLayout->setObjectName("leftLayout");
        userSearch = new QLineEdit(leftSection);
        userSearch->setObjectName("userSearch");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userSearch->sizePolicy().hasHeightForWidth());
        userSearch->setSizePolicy(sizePolicy1);

        leftLayout->addWidget(userSearch);

        chatList = new QListWidget(leftSection);
        chatList->setObjectName("chatList");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chatList->sizePolicy().hasHeightForWidth());
        chatList->setSizePolicy(sizePolicy2);
        chatList->setMinimumSize(QSize(200, 0));
        chatList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));

        leftLayout->addWidget(chatList);


        horizontalLayout->addWidget(leftSection);

        rightSection = new QWidget(layoutWidget);
        rightSection->setObjectName("rightSection");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(3);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rightSection->sizePolicy().hasHeightForWidth());
        rightSection->setSizePolicy(sizePolicy3);
        rightSection->setStyleSheet(QString::fromUtf8("\n"
"       QWidget#rightSection {\n"
"           background-color: #ffffff;\n"
"       }\n"
"       QWidget#header {\n"
"           background-color: #f8f8f8;\n"
"           border-bottom: 1px solid #dcdcdc;\n"
"           padding: 10px;\n"
"       }\n"
"       QLabel#contactName {\n"
"           font-size: 18px;\n"
"           font-weight: bold;\n"
"			color:black;\n"
"       }\n"
"       QListWidget#conversationHistory {\n"
"           padding: 10px;\n"
"       }\n"
"       QWidget#composer {\n"
"           background-color: #f8f8f8;\n"
"           border-top: 1px solid #dcdcdc;\n"
"           padding: 5px;\n"
"       }\n"
"       QLineEdit#messageInput {\n"
"           font-size: 14px;\n"
"           padding: 5px;\n"
"           border: 1px solid #dcdcdc;\n"
"           border-radius: 5px;\n"
"       }\n"
"       QPushButton#attachButton, QPushButton#sendButton {\n"
"           font-size: 14px;\n"
"           padding: 5px 10px;\n"
"           margin-left: 5px;\n"
"       }\n"
"       QPushButton#sendButton"
                        " {\n"
"           background-color: #4CAF50;\n"
"           color: white;\n"
"           border: none;\n"
"           border-radius: 5px;\n"
"       }\n"
"       QPushButton#sendButton:hover {\n"
"           background-color: #45a049;\n"
"       }\n"
"  QPushButton#attachButton:hover {\n"
"           background-color: #FFFFFF;\n"
"color:black;\n"
"		  border: none;\n"
"           border-radius: 5px;\n"
"       }\n"
"      "));
        rightLayout = new QVBoxLayout(rightSection);
        rightLayout->setObjectName("rightLayout");
        header = new QWidget(rightSection);
        header->setObjectName("header");
        headerLayout = new QHBoxLayout(header);
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(-1, 8, -1, 9);
        contactName = new QLabel(header);
        contactName->setObjectName("contactName");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(4);
        sizePolicy4.setVerticalStretch(5);
        sizePolicy4.setHeightForWidth(contactName->sizePolicy().hasHeightForWidth());
        contactName->setSizePolicy(sizePolicy4);
        QFont font;
        font.setFamilies({QString::fromUtf8("Ink Free")});
        font.setBold(true);
        font.setKerning(false);
        contactName->setFont(font);
        contactName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        contactName->setWordWrap(true);

        headerLayout->addWidget(contactName);


        rightLayout->addWidget(header);

        conversationHistory = new QListWidget(rightSection);
        conversationHistory->setObjectName("conversationHistory");
        sizePolicy2.setHeightForWidth(conversationHistory->sizePolicy().hasHeightForWidth());
        conversationHistory->setSizePolicy(sizePolicy2);
        conversationHistory->setMinimumSize(QSize(0, 0));

        rightLayout->addWidget(conversationHistory);

        composer = new QWidget(rightSection);
        composer->setObjectName("composer");
        composerLayout = new QHBoxLayout(composer);
        composerLayout->setObjectName("composerLayout");
        messageInput = new QLineEdit(composer);
        messageInput->setObjectName("messageInput");
        sizePolicy1.setHeightForWidth(messageInput->sizePolicy().hasHeightForWidth());
        messageInput->setSizePolicy(sizePolicy1);

        composerLayout->addWidget(messageInput);

        attachButton = new QPushButton(composer);
        attachButton->setObjectName("attachButton");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(attachButton->sizePolicy().hasHeightForWidth());
        attachButton->setSizePolicy(sizePolicy5);
        attachButton->setCursor(QCursor(Qt::PointingHandCursor));

        composerLayout->addWidget(attachButton);

        sendButton = new QPushButton(composer);
        sendButton->setObjectName("sendButton");
        sizePolicy5.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy5);
        sendButton->setCursor(QCursor(Qt::PointingHandCursor));

        composerLayout->addWidget(sendButton);


        rightLayout->addWidget(composer);


        horizontalLayout->addWidget(rightSection);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        MainChatWindow->setCentralWidget(layoutWidget);
        menuBar = new QMenuBar(MainChatWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName("menuOptions");
        MainChatWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addSeparator();
        menuOptions->addSeparator();
        menuOptions->addAction(actionConnect);
        menuOptions->addSeparator();
        menuOptions->addAction(actionExit);

        retranslateUi(MainChatWindow);

        QMetaObject::connectSlotsByName(MainChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainChatWindow)
    {
        MainChatWindow->setWindowTitle(QCoreApplication::translate("MainChatWindow", "Chat Application", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainChatWindow", "Connect", nullptr));
        actionExit->setText(QCoreApplication::translate("MainChatWindow", "Exit", nullptr));
        userSearch->setPlaceholderText(QCoreApplication::translate("MainChatWindow", "Search by Username...", nullptr));
        contactName->setText(QCoreApplication::translate("MainChatWindow", "Open a Chat, let's Chat", nullptr));
        messageInput->setPlaceholderText(QCoreApplication::translate("MainChatWindow", "Type a message...", nullptr));
        attachButton->setText(QCoreApplication::translate("MainChatWindow", "Attach", nullptr));
        sendButton->setText(QCoreApplication::translate("MainChatWindow", "Send", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainChatWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainChatWindow: public Ui_MainChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCHATWINDOW_H
