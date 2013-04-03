/********************************************************************************
** Form generated from reading UI file 'passwordchangedialog.ui'
**
** Created: Wed 3. Apr 22:05:12 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDCHANGEDIALOG_H
#define UI_PASSWORDCHANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PasswordChangeDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_oldp;
    QLineEdit *lineEdit_newp;
    QLineEdit *lineEdit_rnewp;
    QPushButton *pushOk;
    QPushButton *pushCancel;

    void setupUi(QDialog *PasswordChangeDialog)
    {
        if (PasswordChangeDialog->objectName().isEmpty())
            PasswordChangeDialog->setObjectName(QString::fromUtf8("PasswordChangeDialog"));
        PasswordChangeDialog->resize(366, 227);
        label = new QLabel(PasswordChangeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 81, 16));
        label_2 = new QLabel(PasswordChangeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 81, 16));
        label_3 = new QLabel(PasswordChangeDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 121, 16));
        lineEdit_oldp = new QLineEdit(PasswordChangeDialog);
        lineEdit_oldp->setObjectName(QString::fromUtf8("lineEdit_oldp"));
        lineEdit_oldp->setGeometry(QRect(150, 40, 151, 20));
        lineEdit_oldp->setMaxLength(128);
        lineEdit_oldp->setEchoMode(QLineEdit::Password);
        lineEdit_newp = new QLineEdit(PasswordChangeDialog);
        lineEdit_newp->setObjectName(QString::fromUtf8("lineEdit_newp"));
        lineEdit_newp->setGeometry(QRect(150, 80, 151, 20));
        lineEdit_newp->setMaxLength(128);
        lineEdit_newp->setEchoMode(QLineEdit::Password);
        lineEdit_rnewp = new QLineEdit(PasswordChangeDialog);
        lineEdit_rnewp->setObjectName(QString::fromUtf8("lineEdit_rnewp"));
        lineEdit_rnewp->setGeometry(QRect(150, 120, 151, 20));
        lineEdit_rnewp->setMaxLength(128);
        lineEdit_rnewp->setEchoMode(QLineEdit::Password);
        pushOk = new QPushButton(PasswordChangeDialog);
        pushOk->setObjectName(QString::fromUtf8("pushOk"));
        pushOk->setGeometry(QRect(60, 180, 75, 23));
        pushCancel = new QPushButton(PasswordChangeDialog);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(190, 180, 75, 23));

        retranslateUi(PasswordChangeDialog);

        QMetaObject::connectSlotsByName(PasswordChangeDialog);
    } // setupUi

    void retranslateUi(QDialog *PasswordChangeDialog)
    {
        PasswordChangeDialog->setWindowTitle(QApplication::translate("PasswordChangeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PasswordChangeDialog", "Old password:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PasswordChangeDialog", "New password:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PasswordChangeDialog", "Repeat new password:", 0, QApplication::UnicodeUTF8));
        pushOk->setText(QApplication::translate("PasswordChangeDialog", "Ok", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("PasswordChangeDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PasswordChangeDialog: public Ui_PasswordChangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCHANGEDIALOG_H
