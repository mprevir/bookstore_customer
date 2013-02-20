#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "QDebug.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->label_3->setVisible(false);
}

login::~login()
{
    delete ui;
}

void login::addMW(MainWindow *MW) {
    this->mainW = MW;
}


void login::on_pushButton_Ok_clicked()
{
    const QString* correct_login = new QString("previr");
    const QString* correct_password = new QString("1111");
    if (ui->lineEdit_login->text() == correct_login && ui->lineEdit_password->text() == correct_password)
    {
        this->setVisible(false);
        mainW->centralWidget()->setVisible(true);
        mainW->dbget_Book();
        mainW->setUsername(ui->lineEdit_login->text());
        mainW->populate_table();

    } else ui->label_3->setVisible(true);
}
