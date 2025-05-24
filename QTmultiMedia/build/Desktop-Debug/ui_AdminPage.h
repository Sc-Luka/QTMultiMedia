/********************************************************************************
** Form generated from reading UI file 'AdminPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminPage
{
public:
    QLineEdit *lineEdit;
    QPushButton *DeleteUser;
    QPushButton *AddUser;
    QPushButton *resetPass;
    QTableView *userTableView;
    QPushButton *Backbutton;

    void setupUi(QWidget *AdminPage)
    {
        if (AdminPage->objectName().isEmpty())
            AdminPage->setObjectName(QString::fromUtf8("AdminPage"));
        AdminPage->resize(905, 456);
        lineEdit = new QLineEdit(AdminPage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 821, 71));
        QFont font;
        font.setPointSize(30);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        DeleteUser = new QPushButton(AdminPage);
        DeleteUser->setObjectName(QString::fromUtf8("DeleteUser"));
        DeleteUser->setGeometry(QRect(550, 110, 261, 41));
        AddUser = new QPushButton(AdminPage);
        AddUser->setObjectName(QString::fromUtf8("AddUser"));
        AddUser->setGeometry(QRect(546, 275, 261, 41));
        resetPass = new QPushButton(AdminPage);
        resetPass->setObjectName(QString::fromUtf8("resetPass"));
        resetPass->setGeometry(QRect(550, 190, 261, 41));
        userTableView = new QTableView(AdminPage);
        userTableView->setObjectName(QString::fromUtf8("userTableView"));
        userTableView->setGeometry(QRect(20, 110, 521, 281));
        Backbutton = new QPushButton(AdminPage);
        Backbutton->setObjectName(QString::fromUtf8("Backbutton"));
        Backbutton->setGeometry(QRect(30, 400, 87, 26));

        retranslateUi(AdminPage);

        QMetaObject::connectSlotsByName(AdminPage);
    } // setupUi

    void retranslateUi(QWidget *AdminPage)
    {
        AdminPage->setWindowTitle(QCoreApplication::translate("AdminPage", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("AdminPage", "Admin page", nullptr));
        DeleteUser->setText(QCoreApplication::translate("AdminPage", "Delete User", nullptr));
        AddUser->setText(QCoreApplication::translate("AdminPage", "Add User", nullptr));
        resetPass->setText(QCoreApplication::translate("AdminPage", "Reset Password", nullptr));
        Backbutton->setText(QCoreApplication::translate("AdminPage", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPage: public Ui_AdminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
