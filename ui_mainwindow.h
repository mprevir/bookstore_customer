/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 27. Mar 21:48:32 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView_Books;
    QPushButton *pushButton_Prev;
    QPushButton *pushButton_Next;
    QWidget *tab_2;
    QTableView *tableView_Bundles;
    QWidget *tab_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableView *tableView_Cart;
    QWidget *tab_4;
    QTableView *tableView_History;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_account;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(685, 492);
        MainWindow->setMinimumSize(QSize(685, 468));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 10, 121, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 10, 46, 21));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 110, 641, 371));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView_Books = new QTableView(tab);
        tableView_Books->setObjectName(QString::fromUtf8("tableView_Books"));
        tableView_Books->setGeometry(QRect(0, 0, 641, 321));
        pushButton_Prev = new QPushButton(tab);
        pushButton_Prev->setObjectName(QString::fromUtf8("pushButton_Prev"));
        pushButton_Prev->setGeometry(QRect(0, 320, 75, 23));
        pushButton_Next = new QPushButton(tab);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(560, 320, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableView_Bundles = new QTableView(tab_2);
        tableView_Bundles->setObjectName(QString::fromUtf8("tableView_Bundles"));
        tableView_Bundles->setGeometry(QRect(0, 0, 641, 321));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 280, 151, 23));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 280, 141, 23));
        tableView_Cart = new QTableView(tab_3);
        tableView_Cart->setObjectName(QString::fromUtf8("tableView_Cart"));
        tableView_Cart->setGeometry(QRect(0, 0, 641, 271));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tableView_History = new QTableView(tab_4);
        tableView_History->setObjectName(QString::fromUtf8("tableView_History"));
        tableView_History->setGeometry(QRect(0, 0, 641, 321));
        tabWidget->addTab(tab_4, QString());
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 121, 16));
        QFont font;
        font.setPointSize(10);
        label_3->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 171, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 50, 75, 23));
        pushButton_account = new QPushButton(centralWidget);
        pushButton_account->setObjectName(QString::fromUtf8("pushButton_account"));
        pushButton_account->setGeometry(QRect(460, 30, 171, 23));
        MainWindow->setCentralWidget(centralWidget);
        pushButton_account->raise();
        label->raise();
        label_2->raise();
        tabWidget->raise();
        label_3->raise();
        lineEdit->raise();
        pushButton->raise();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bookstore", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "username's account", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "$0.00", 0, QApplication::UnicodeUTF8));
        pushButton_Prev->setText(QApplication::translate("MainWindow", "<<", 0, QApplication::UnicodeUTF8));
        pushButton_Next->setText(QApplication::translate("MainWindow", ">>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Books", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Bundles", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Clear Cart", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Purchase", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Cart", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Purchased/Rented books", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Search the store:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        pushButton_account->setText(QApplication::translate("MainWindow", "Profile", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
