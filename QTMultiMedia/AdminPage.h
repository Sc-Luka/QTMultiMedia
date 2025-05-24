#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>

namespace Ui {
class AdminPage;
}

class AdminPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_Backbutton_clicked();

    void on_DeleteUser_clicked();

    void on_resetPass_clicked();

    void on_AddUser_clicked();

private:
    Ui::AdminPage *ui;
    void loadUsers();
};

#endif // ADMINPAGE_H
