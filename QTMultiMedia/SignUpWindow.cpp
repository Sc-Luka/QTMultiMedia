#include "SignUpWindow.h"
#include "ui_SignUpWindow.h"
#include "MainWindow.h"

#include <QMessageBox>
#include <QScreen>
#include <QSqlError>
#include <QSqlQuery>
#include <QRect>
#include <QDebug>

SignUpWindow::SignUpWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);

    ui->enteredPass->setEchoMode(QLineEdit::Password);
    ui->reEnterdPass->setEchoMode(QLineEdit::Password);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}


void SignUpWindow::on_SignUpButton_clicked()
{
    QString username = ui->enteredUser->text();
    QString password = ui->enteredPass->text();
    QString repassword = ui->reEnterdPass->text();
    if( username.isEmpty() || password.isEmpty() || repassword.isEmpty() ){
        QMessageBox::warning(this, "Input Error", "Please enter a username and both password fields.");
        return;
    }
    if(password!=repassword){
        QMessageBox::warning(this, "Password Mismatch", "Passwords do not match.");
        return;
    }
    //useri tu arsebobs
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id FROM users WHERE username = :username");
    checkQuery.bindValue(":username", username);
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "Error checking username.\n" + checkQuery.lastError().text());
        return;
    }
    if (checkQuery.next()) {
        QMessageBox::warning(this, "Username Taken", "This username is already used. Please choose another.");
        return;
    }
    //vamateb
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    insertQuery.bindValue(":username",username);
    insertQuery.bindValue(":password",password);
    if (!insertQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "Error inserting user.\n" + insertQuery.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "User registered successfully.");

    on_BackButton_clicked();


}


void SignUpWindow::on_BackButton_clicked()
{
    MainWindow *mainwindow = new MainWindow();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();


    mainwindow->move(screenGeometry.center() - mainwindow->rect().center());

    mainwindow->show();
    this->hide();
}

