QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "C:/QtProjects/ChatApplication/Client"

SOURCES += \
    MainChatWindow.cpp \
    RegisterWindow.cpp \
    UserChatItemWidget.cpp \
    main.cpp \
    LoginWindow.cpp \
    chatWidgeClient.cpp \
        serverManager.cpp \
        serverwindow.cpp \
        ChatItemWidget.cpp \
            ClientManager.cpp \
            clientWindow.cpp




HEADERS += \
    LoginWindow.h \
    MainChatWindow.h \
    RegisterWindow.h \
    UserChatItemWidget.h \
    chatWidgeClient.h \
        serverManager.h \
        serverwindow.h \
        ChatItemWidget.h \
            ClientManager.h \
            clientWindow.h



FORMS += \
    LoginWindow.ui \
    MainChatWindow.ui \
    RegisterWindow.ui \
    UserChatItemWidget.ui \
    chatWidgeClient.ui \
        serverwindow.ui \
        ChatItemWidget.ui \
            clientWindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    rec.qrc
