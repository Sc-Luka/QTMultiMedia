/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SignUpButton;
    QPushButton *SignInButton;
    QLineEdit *userNameField;
    QLineEdit *passField;
    QLineEdit *Text2;
    QLineEdit *Text3;
    QLineEdit *Text1;
    QLineEdit *Text2_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(629, 411);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SignUpButton = new QPushButton(centralwidget);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));
        SignUpButton->setGeometry(QRect(190, 320, 87, 26));
        SignInButton = new QPushButton(centralwidget);
        SignInButton->setObjectName(QString::fromUtf8("SignInButton"));
        SignInButton->setGeometry(QRect(240, 230, 87, 26));
        userNameField = new QLineEdit(centralwidget);
        userNameField->setObjectName(QString::fromUtf8("userNameField"));
        userNameField->setGeometry(QRect(310, 100, 113, 26));
        passField = new QLineEdit(centralwidget);
        passField->setObjectName(QString::fromUtf8("passField"));
        passField->setGeometry(QRect(310, 160, 113, 26));
        Text2 = new QLineEdit(centralwidget);
        Text2->setObjectName(QString::fromUtf8("Text2"));
        Text2->setGeometry(QRect(170, 100, 81, 26));
        Text2->setReadOnly(true);
        Text3 = new QLineEdit(centralwidget);
        Text3->setObjectName(QString::fromUtf8("Text3"));
        Text3->setGeometry(QRect(170, 160, 81, 26));
        Text3->setReadOnly(true);
        Text1 = new QLineEdit(centralwidget);
        Text1->setObjectName(QString::fromUtf8("Text1"));
        Text1->setGeometry(QRect(10, 320, 161, 26));
        Text1->setReadOnly(true);
        Text2_2 = new QLineEdit(centralwidget);
        Text2_2->setObjectName(QString::fromUtf8("Text2_2"));
        Text2_2->setGeometry(QRect(160, 10, 311, 61));
        QFont font;
        font.setPointSize(30);
        Text2_2->setFont(font);
        Text2_2->setAlignment(Qt::AlignCenter);
        Text2_2->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 629, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SignUpButton->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        SignInButton->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        Text2->setText(QCoreApplication::translate("MainWindow", "username : ", nullptr));
        Text3->setText(QCoreApplication::translate("MainWindow", "password : ", nullptr));
        Text1->setText(QCoreApplication::translate("MainWindow", "Don't have account", nullptr));
        Text2_2->setText(QCoreApplication::translate("MainWindow", "log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
