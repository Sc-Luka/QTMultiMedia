#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H


#include <QWidget>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:

    void on_SignUpButton_clicked();


    void on_BackButton_clicked();

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
