/********************************************************************************
** Form generated from reading UI file 'bundleinfo.ui'
**
** Created: Wed 3. Apr 20:17:20 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUNDLEINFO_H
#define UI_BUNDLEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BundleInfo
{
public:
    QPushButton *pushAdd_to_cart;
    QPushButton *pushClose;
    QLabel *label;
    QTableView *tableBundle_items;

    void setupUi(QDialog *BundleInfo)
    {
        if (BundleInfo->objectName().isEmpty())
            BundleInfo->setObjectName(QString::fromUtf8("BundleInfo"));
        BundleInfo->resize(571, 300);
        pushAdd_to_cart = new QPushButton(BundleInfo);
        pushAdd_to_cart->setObjectName(QString::fromUtf8("pushAdd_to_cart"));
        pushAdd_to_cart->setGeometry(QRect(110, 260, 75, 23));
        pushClose = new QPushButton(BundleInfo);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setGeometry(QRect(380, 260, 75, 23));
        label = new QLabel(BundleInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 0, 341, 51));
        tableBundle_items = new QTableView(BundleInfo);
        tableBundle_items->setObjectName(QString::fromUtf8("tableBundle_items"));
        tableBundle_items->setGeometry(QRect(30, 50, 511, 192));
        tableBundle_items->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableBundle_items->setSelectionMode(QAbstractItemView::SingleSelection);

        retranslateUi(BundleInfo);

        QMetaObject::connectSlotsByName(BundleInfo);
    } // setupUi

    void retranslateUi(QDialog *BundleInfo)
    {
        BundleInfo->setWindowTitle(QApplication::translate("BundleInfo", "Dialog", 0, QApplication::UnicodeUTF8));
        pushAdd_to_cart->setText(QApplication::translate("BundleInfo", "Add to cart", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("BundleInfo", "Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BundleInfo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Bundle name</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BundleInfo: public Ui_BundleInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUNDLEINFO_H
