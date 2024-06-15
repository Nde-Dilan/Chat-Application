#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "ui_RegisterWindow.h"


RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QtProjects/ChatApplication/LoginApplication/chat.db");
    db.open();
    if(!db.isOpen()){
        qDebug() << "Failed to open the database";
    }
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_regBtn_clicked()
{
    // Get user input from UI elements (assuming QLineEdit objects)
    QString username = ui->username->text().trimmed();
    QString email = ui->email->text().trimmed();
    QString password = ui->password->text().trimmed();
    QString confirmPassword = ui->confirm_password->text().trimmed();


    // Validate for empty fields
    if (username.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "Please fill in all registration fields.");
        return;
    }

    // Validate password confirmation
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Password Mismatch", "Passwords do not match. Please re-enter your password.");
        return;
    }

    QString hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Connect to the database (handle potential exceptions)
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database.");
        return;
    }

    // Prepare SQL query to check for existing username (prevent duplicate usernames)
    QSqlQuery checkUsernameSql(db);
    checkUsernameSql.prepare("SELECT * FROM users WHERE name = :username");
    checkUsernameSql.bindValue(":username", username);

    // Execute username check query and handle potential exceptions
    if (!checkUsernameSql.exec()) {
        QMessageBox::critical(this, "Registration Error", "An error occurred while checking username: " + checkUsernameSql.lastError().text());
        db.close(); // Close database connection even on error
        return;
    }

    // Check if username already exists
    if (checkUsernameSql.next()) {
        QMessageBox::warning(this, "Registration Failed", "Username already exists. Please choose a different username.");
        db.close(); // Close database connection after checking username
        return;
    }

    // Prepare SQL query for registration (use placeholders for security)
    QSqlQuery insertSql(db);
    insertSql.prepare("INSERT INTO users (name, email, password,avatar) VALUES (:username, :email, :password,:avatar)");
    insertSql.bindValue(":username", username);
    insertSql.bindValue(":email", email);
    insertSql.bindValue(":password", hashedPassword);
    insertSql.bindValue(":avatar", QString("icons/user.png"));


    // Execute registration query and handle potential exceptions
    if (!insertSql.exec()) {
        QMessageBox::critical(this, "Registration Error", "An error occurred during registration: " + insertSql.lastError().text());
        db.close(); // Close database connection even on error
        return;
    }

    QMessageBox::information(this, "Registration Successful", "Registration successful! You can now log in.");
    // Handle successful registration (e.g., clear registration fields, show login window)
    LoginWindow *loginWindow = new LoginWindow();
     db.close(); // Close database connection after successful execution
    this->close();
    loginWindow->show();

}



void RegisterWindow::on_logInBtn_clicked()
{
    LoginWindow *loginWindow = new LoginWindow();
    this->close();
    loginWindow->show();
}




