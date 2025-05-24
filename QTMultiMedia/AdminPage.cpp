#include "AdminPage.h"
#include "ui_AdminPage.h"
#include "MainWindow.h"

#include <QSqlTableModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QScreen>
#include <QRect>

void AdminPage::loadUsers() {
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable("users");
    model->setFilter("id > 0");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Username");
    model->setHeaderData(2, Qt::Horizontal, "Password");

    ui->userTableView->setModel(model);
    ui->userTableView->resizeColumnsToContents();
}

AdminPage::AdminPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    loadUsers();
}

AdminPage::~AdminPage()
{
    delete ui;
}


void AdminPage::on_Backbutton_clicked()
{
    MainWindow *mainwindow = new MainWindow();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    mainwindow->move(screenGeometry.center() - mainwindow->rect().center());

    mainwindow->show();
    this->hide();
}


void AdminPage::on_DeleteUser_clicked()
{
    bool ok;
    int id = QInputDialog::getInt(this, "Delete User",
                                  "Enter User ID to delete:",
                                  1, 1, 1000000, 1, &ok);

    if (!ok) return;

    if(id<=0){
        QMessageBox::warning(this, "Invalid ID", "Cannot delete admin, or It is invalid user ID.");
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete user.\n" + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "User deleted successfully.");
    loadUsers();

}


void AdminPage::on_resetPass_clicked()
{
    bool ok;
    int userId=QInputDialog::getInt(this, "Change Password", "Enter User ID to change password:",
                                      1, 1, 1000000, 1, &ok);
    if (!ok || userId <= 0) {
        QMessageBox::warning(this, "Invalid ID", "Please enter a valid User ID.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "User Not Found", "The user ID you entered does not exist.");
        return;
    }

    QString newPassword = QInputDialog::getText(this, "Change Password window ", "Enter new password:");
    if (!ok || newPassword.isEmpty()) {
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE users SET password = :password WHERE id = :id");
    updateQuery.bindValue(":id", userId);
    updateQuery.bindValue(":password",newPassword);
    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Error", "Failed to change password.\n" + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Password changed successfully.");

    loadUsers();

}


void AdminPage::on_AddUser_clicked()
{
    bool ok1, ok2;
    QString password;
    QString username = QInputDialog::getText(this, "Add User", "Enter username:", QLineEdit::Normal, "", &ok1);

    if (! (!ok1 ||  username.isEmpty()) ){

        password = QInputDialog::getText(this, "Add User", "Enter password:", QLineEdit::Normal, "", &ok2);
        if (!ok2 || password.isEmpty())
            return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password",password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to add user.\n" + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "User added successfully.");

    loadUsers();
}

