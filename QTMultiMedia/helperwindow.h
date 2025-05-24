#ifndef HELPERWINDOW_H
#define HELPERWINDOW_H

#include <QWidget>

namespace Ui {
class HelperWindow;
}

class HelperWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HelperWindow(QWidget *parent = nullptr);
    ~HelperWindow();

private:
    Ui::HelperWindow *ui;
};

#endif // HELPERWINDOW_H
