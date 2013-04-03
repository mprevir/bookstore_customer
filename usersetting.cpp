#include "usersetting.h"
#include "ui_usersetting.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "passwordchangedialog.h"

UserSetting::UserSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSetting)
{
    ui->setupUi(this);
    update_wallet();
}

UserSetting::UserSetting(QWidget *parent, int customer_id) :
    QDialog(parent),
    ui(new Ui::UserSetting),
    current_customer_id(customer_id)
{
    ui->setupUi(this);
    QSqlDatabase::database().open();
    QSqlQuery query;
    query.prepare("select customer.name from customer where customer_id = :id");
    query.bindValue(":id", current_customer_id);
    qDebug()<<"\nProfile exec: "<<query.exec();
    qDebug()<<query.lastError();
    query.next();
    ui->label_accountName->setText(query.value(0).toString());
    QSqlDatabase::database().close();
    update_wallet();
}

UserSetting::~UserSetting()
{
    delete ui;
}

void UserSetting::on_closeButton_clicked()
{
    exit_status = 1;
    close();
}

void UserSetting::on_logoutButton_clicked()
{
    exit_status = 0;
    close();
}

void UserSetting::update_wallet()
{
    QSqlDatabase::database().open();
    QSqlQuery query;
    qDebug()<<"Current ID: "<<current_customer_id;
    query.prepare("select wallet from customer where customer_id = :id");
    query.bindValue(":id", current_customer_id);
    qDebug()<<"constructor query exec: "<<query.exec();
    qDebug()<<"query.next - "<<query.next();
    qDebug()<<"Last Error: "<<query.lastError();
    double money = query.value(0).toDouble();
    qDebug()<<"Money: "<<money;
    QSqlDatabase::database().close();
    ui->label_Wallet->setText(QString::number(money, 'f', 2) + '$');
}

void UserSetting::on_pushButton_clicked()
{
    QSqlDatabase::database().open();
    QSqlQuery query;
    query.prepare("call ADD_FUNDS(:customer_id, 10)");
    query.bindValue(":customer_id", current_customer_id);
    qDebug()<<"Query exec: "<<query.exec();
    QSqlDatabase::database().close();
    update_wallet();
}
void UserSetting::on_pushChange_pswd_clicked()
{
    PasswordChangeDialog pswdChange;
    pswdChange.customer_id = current_customer_id;
    pswdChange.exec();
}
