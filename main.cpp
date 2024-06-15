#include "LoginWindow.h"
#include "MainChatWindow.h"
#include "serverwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainChatWindow w(4000,1);
    MainChatWindow w1(4500,2);
    ServerWindow s1(4000);
    ServerWindow s2(4500);
    LoginWindow w;
    w.show();
     // w1.show();
    s1.show();
     // s2.show();
    return a.exec();
}
