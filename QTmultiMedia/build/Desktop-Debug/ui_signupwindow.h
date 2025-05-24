/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QLineEdit *Text1;
    QLineEdit *Text2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *enteredPass;
    QLineEdit *Text3;
    QLineEdit *enteredUser;
    QLineEdit *reEnterdPass;
    QLineEdit *Text4;

    void setupUi(QWidget *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName(QString::fromUtf8("SignUpWindow"));
        SignUpWindow->resize(771, 445);
        Text1 = new QLineEdit(SignUpWindow);
        Text1->setObjectName(QString::fromUtf8("Text1"));
        Text1->setGeometry(QRect(180, 180, 131, 26));
        Text1->setAlignment(Qt::AlignCenter);
        Text1->setReadOnly(true);
        Text2 = new QLineEdit(SignUpWindow);
        Text2->setObjectName(QString::fromUtf8("Text2"));
        Text2->setGeometry(QRect(170, 60, 431, 71));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(true);
        Text2->setFont(font);
        Text2->setAlignment(Qt::AlignCenter);
        Text2->setReadOnly(true);
        pushButton = new QPushButton(SignUpWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 400, 87, 26));
        pushButton_2 = new QPushButton(SignUpWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 330, 131, 26));
        enteredPass = new QLineEdit(SignUpWindow);
        enteredPass->setObjectName(QString::fromUtf8("enteredPass"));
        enteredPass->setGeometry(QRect(420, 230, 113, 26));
        enteredPass->setAlignment(Qt::AlignCenter);
        Text3 = new QLineEdit(SignUpWindow);
        Text3->setObjectName(QString::fromUtf8("Text3"));
        Text3->setGeometry(QRect(180, 230, 131, 26));
        Text3->setAlignment(Qt::AlignCenter);
        Text3->setReadOnly(true);
        enteredUser = new QLineEdit(SignUpWindow);
        enteredUser->setObjectName(QString::fromUtf8("enteredUser"));
        enteredUser->setGeometry(QRect(420, 180, 113, 26));
        enteredUser->setAlignment(Qt::AlignCenter);
        reEnterdPass = new QLineEdit(SignUpWindow);
        reEnterdPass->setObjectName(QString::fromUtf8("reEnterdPass"));
        reEnterdPass->setGeometry(QRect(420, 280, 113, 26));
        reEnterdPass->setAlignment(Qt::AlignCenter);
        Text4 = new QLineEdit(SignUpWindow);
        Text4->setObjectName(QString::fromUtf8("Text4"));
        Text4->setGeometry(QRect(180, 280, 131, 26));
        Text4->setAlignment(Qt::AlignCenter);
        Text4->setReadOnly(true);

        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QWidget *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "Form", nullptr));
        Text1->setText(QCoreApplication::translate("SignUpWindow", "enter username :", nullptr));
        Text2->setText(QCoreApplication::translate("SignUpWindow", "Sign Up", nullptr));
        pushButton->setText(QCoreApplication::translate("SignUpWindow", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SignUpWindow", "Sign up", nullptr));
        Text3->setText(QCoreApplication::translate("SignUpWindow", "enter password:", nullptr));
        Text4->setText(QCoreApplication::translate("SignUpWindow", "re-enter password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
