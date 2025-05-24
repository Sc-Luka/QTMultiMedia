#include "helperwindow.h"
#include "ui_helperwindow.h"

HelperWindow::HelperWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelperWindow)
{
    ui->setupUi(this);
}

HelperWindow::~HelperWindow()
{
    delete ui;
}
