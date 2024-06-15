#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:

    void on_logBtn_clicked();

    void on_registerBtn_clicked();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H
