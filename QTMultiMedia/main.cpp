#include "MainWindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QApplication>


bool connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("myapp");
    db.setUserName("kali");
    db.setPassword("yourpassword");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error",
                              "Cannot connect to database: " + db.lastError().text());
        return false;
    }
    qDebug() << "Connected to the database successfully!";
    return true;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!connectToDatabase()) {
        return -1;
    }
    MainWindow w;
    w.show();
    return a.exec();

}
