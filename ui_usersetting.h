/********************************************************************************
** Form generated from reading UI file 'usersetting.ui'
**
** Created: Wed 27. Mar 21:48:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSETTING_H
#define UI_USERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserSetting
{
public:
    QLabel *label_accountName;
    QLabel *label;
    QLabel *label_Wallet;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *logoutButton;
    QPushButton *closeButton;

    void setupUi(QDialog *UserSetting)
    {
        if (UserSetting->objectName().isEmpty())
            UserSetting->setObjectName(QString::fromUtf8("UserSetting"));
        UserSetting->resize(255, 315);
        label_accountName = new QLabel(UserSetting);
        label_accountName->setObjectName(QString::fromUtf8("label_accountName"));
        label_accountName->setGeometry(QRect(30, 0, 151, 31));
        QFont font;
        font.setPointSize(12);
        label_accountName->setFont(font);
        label = new QLabel(UserSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 95, 46, 13));
        label_Wallet = new QLabel(UserSetting);
        label_Wallet->setObjectName(QString::fromUtf8("label_Wallet"));
        label_Wallet->setGeometry(QRect(70, 95, 46, 13));
        pushButton = new QPushButton(UserSetting);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 90, 75, 23));
        pushButton_2 = new QPushButton(UserSetting);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 40, 121, 23));
        logoutButton = new QPushButton(UserSetting);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setGeometry(QRect(50, 270, 75, 23));
        closeButton = new QPushButton(UserSetting);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(140, 270, 75, 23));

        retranslateUi(UserSetting);

        QMetaObject::connectSlotsByName(UserSetting);
    } // setupUi

    void retranslateUi(QDialog *UserSetting)
    {
        UserSetting->setWindowTitle(QApplication::translate("UserSetting", "Dialog", 0, QApplication::UnicodeUTF8));
        label_accountName->setText(QApplication::translate("UserSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">TextLabel</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserSetting", "Wallet:", 0, QApplication::UnicodeUTF8));
        label_Wallet->setText(QString());
        pushButton->setText(QApplication::translate("UserSetting", "Add funds", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("UserSetting", "Change Password", 0, QApplication::UnicodeUTF8));
        logoutButton->setText(QApplication::translate("UserSetting", "LogOut", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("UserSetting", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserSetting: public Ui_UserSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSETTING_H
