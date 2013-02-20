#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QRadioButton *purch_button = new QRadioButton("Purchase", ui->tableWidget_3);
    ui->tableWidget_3->setCellWidget(0,5,new QCheckBox(ui->tableWidget_3));
    ui->tableWidget_3->setCellWidget(0,6, new QPushButton("Delete", ui->tableWidget_3));
    ui->centralWidget->setVisible(false);

    if(!QSqlDatabase::isDriverAvailable("QOCI"))
    {
    qFatal("Driver not loaded");
    qDebug()<<"fuck";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QOCI");
    db.setHostName("localhost");
    db.setDatabaseName("previrpc");
    db.setUserName("previrpc");
    db.setPassword("aaaa");
    bool ok = db.open();
    qDebug()<<ok;
    qDebug()<<db.lastError();

    login* Login = new login(this);
    Login->addMW(this);
    Login->show();
}

void MainWindow::setUsername(QString usern) {
    username = usern;
    ui->label->setText(username);
}

void MainWindow::dbget_Book() {

    QSqlQuery query;
    Book tBook;
    QString tISBN;
    int tPublisherID;
    QString tTitle;
    float tPrice;
    int tQuantity;

    query.exec("SELECT title, price, quantity, ISBN, publisher_ID FROM BOOK");
    while (query.next()) {
        tTitle = query.value(0).toString();
        qDebug()<<tTitle;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
