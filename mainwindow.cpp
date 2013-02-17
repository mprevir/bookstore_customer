#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QRadioButton *purch_button = new QRadioButton("Purchase", ui->tableWidget_3);
    ui->tableWidget_3->setCellWidget(0,5,new QCheckBox("Purchase", ui->tableWidget_3));

}

MainWindow::~MainWindow()
{
    delete ui;
}
