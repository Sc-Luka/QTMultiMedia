/********************************************************************************
** Form generated from reading UI file 'UserPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPAGE_H
#define UI_USERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserPage
{
public:
    QPushButton *AddItem;
    QPushButton *Show;
    QPushButton *pushButton;

    void setupUi(QWidget *UserPage)
    {
        if (UserPage->objectName().isEmpty())
            UserPage->setObjectName(QString::fromUtf8("UserPage"));
        UserPage->resize(665, 566);
        AddItem = new QPushButton(UserPage);
        AddItem->setObjectName(QString::fromUtf8("AddItem"));
        AddItem->setGeometry(QRect(210, 140, 171, 26));
        Show = new QPushButton(UserPage);
        Show->setObjectName(QString::fromUtf8("Show"));
        Show->setGeometry(QRect(210, 230, 171, 26));
        pushButton = new QPushButton(UserPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 530, 87, 26));

        retranslateUi(UserPage);

        QMetaObject::connectSlotsByName(UserPage);
    } // setupUi

    void retranslateUi(QWidget *UserPage)
    {
        UserPage->setWindowTitle(QCoreApplication::translate("UserPage", "Form", nullptr));
        AddItem->setText(QCoreApplication::translate("UserPage", "Add Item", nullptr));
        Show->setText(QCoreApplication::translate("UserPage", "Show", nullptr));
        pushButton->setText(QCoreApplication::translate("UserPage", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserPage: public Ui_UserPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPAGE_H
