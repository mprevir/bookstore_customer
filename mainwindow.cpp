#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QRadioButton *purch_button = new QRadioButton("Purchase", ui->tableWidget_3);
    ui->tableWidget_3->setCellWidget(0,5,new QCheckBox(ui->tableWidget_3));
    ui->tableWidget_3->setCellWidget(0,6, new QPushButton("Delete", ui->tableWidget_3));

    QSqlDatabase db = QSqlDatabase::addDatabase("QOCI","mydb");
    db.setHostName("localhost");
    db.setDatabaseName("bookstore");
    db.setUserName("previr");
    db.setPassword("aaaa");
    bool ok = db.open();

}

MainWindow::~MainWindow()
{
    delete ui;
}
