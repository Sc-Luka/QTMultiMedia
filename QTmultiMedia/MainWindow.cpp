#include "SignUpWindow.h"
#include "MainWindow.h"
#include "AdminPage.h"
#include "UserPage.h"
#include "ui_MainWindow.h"



#include <QGuiApplication>  // primaryScreen()
#include <QScreen>         //screenGeometry()
#include <QRect>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passField->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SignInButton_clicked()
{


    QString username = ui->userNameField->text();
    QString password = ui->passField->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT id, password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    if(query.next()){

        int userId = query.value("id").toInt();
        QString dbPassword = query.value("password").toString();

        if (password != dbPassword) {
            QMessageBox::warning(this, "Login Failed", "Incorrect password.");
            return;
        }

        switch(userId){
            case 0:{
                    AdminPage *adminPage = new AdminPage();

                    QScreen *screen = QGuiApplication::primaryScreen();
                    QRect screenGeometry = screen->availableGeometry();

                    adminPage->move(screenGeometry.center() - adminPage->rect().center());

                    this->hide();
                    adminPage->show();
                    break;
            }

            default:{

                    UserPage *userPage = new UserPage(userId);

                    QScreen *screen = QGuiApplication::primaryScreen();
                    QRect screenGeometry = screen->availableGeometry();

                    userPage->move(screenGeometry.center() - userPage->rect().center());

                    this->hide();
                    userPage->show();
                    break;
            }
        }
    }else QMessageBox::warning(this, "Login Failed", "Username not found.");
}


void MainWindow::on_SignUpButton_clicked()
{
    SignUpWindow *signup = new SignUpWindow();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    signup->move(screenGeometry.center() - signup->rect().center());

    signup->show();
    this->hide();
}

