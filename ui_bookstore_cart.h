/********************************************************************************
** Form generated from reading UI file 'bookstore_cart.ui'
**
** Created: Sun 17. Feb 19:16:29 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSTORE_CART_H
#define UI_BOOKSTORE_CART_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_bookstore_cart
{
public:
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *bookstore_cart)
    {
        if (bookstore_cart->objectName().isEmpty())
            bookstore_cart->setObjectName(QString::fromUtf8("bookstore_cart"));
        bookstore_cart->resize(643, 429);
        label_2 = new QLabel(bookstore_cart);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(570, 10, 46, 21));
        label = new QLabel(bookstore_cart);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 10, 121, 20));

        retranslateUi(bookstore_cart);

        QMetaObject::connectSlotsByName(bookstore_cart);
    } // setupUi

    void retranslateUi(QDialog *bookstore_cart)
    {
        bookstore_cart->setWindowTitle(QApplication::translate("bookstore_cart", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("bookstore_cart", "$0.00", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("bookstore_cart", "username's account", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class bookstore_cart: public Ui_bookstore_cart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSTORE_CART_H
