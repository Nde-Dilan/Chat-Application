#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "C:/QtProjects/ChatApplication/Client/clientWindow.h"
#include "clientWindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    db =  QSqlDatabase::addDatabase("QSQLITE");
    //Change the path to your path, look for the chat.db file inside LoginApplication and copy
    //and paste the path , don't forget to change the "\" with / do same in RegistrationWindow
    db.setDatabaseName("C:/QtProjects/ChatApplication/LoginApplication/chat.db");
    db.open();
    if(!db.isOpen()){
        qDebug() << "Failed to open the database";
    }
    qDebug() << "Connected Sucessfully";
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_logBtn_clicked()
{

    // Get username and password from UI elements (assuming QLineEdit objects)
    QString username = ui->username->text().trimmed();
    QString password = ui->password->text().trimmed();


    // Validate for empty fields
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "Please enter both username and password.");
        return;
    }

    // Connect to the database (handle potential exceptions)
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database.");
        return;
    }
    QString hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Prepare SQL query with placeholders for security (prevent SQL injection)
    QSqlQuery sql(db);

    sql.prepare("SELECT * FROM users WHERE name = (:username) AND password = (:password)");
    sql.bindValue(":username", username);
    sql.bindValue(":password", hashedPassword);

    // Execute query and handle potential exceptions
    if (!sql.exec()) {
        QMessageBox::critical(this, "Login Error", "An error occurred during login: " + sql.lastError().text());
        db.close(); // Close database connection even on error
        return;
    }

    // Check if login was successful (assuming only one valid user)
    if (sql.next()) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");
        // Handle successful login (e.g., hide login window, show main application window)
        ClientWindow *lientWindow = new ClientWindow();
         db.close(); // Close database connection after successful execution
        this->close();
        lientWindow->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }

    db.close(); // Close database connection after successful execution
}

void LoginWindow::on_registerBtn_clicked()
    {
         db.close();
        RegisterWindow *registrationWindow = new RegisterWindow();
        this->close();
        registrationWindow->show();

    }





