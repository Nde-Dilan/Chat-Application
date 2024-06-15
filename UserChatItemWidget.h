#ifndef USERCHATITEMWIDGET_H
#define USERCHATITEMWIDGET_H

#include <QWidget>

namespace Ui {
class UserChatItemWidget;
}

class UserChatItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserChatItemWidget(QWidget *parent = nullptr);
    ~UserChatItemWidget();
    void setMessage(QString username);


private:
    Ui::UserChatItemWidget *ui;
};

#endif // USERCHATITEMWIDGET_H
