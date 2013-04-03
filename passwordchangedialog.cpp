#include "passwordchangedialog.h"
#include "ui_passwordchangedialog.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

PasswordChangeDialog::PasswordChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordChangeDialog)
{
    ui->setupUi(this);
}

PasswordChangeDialog::~PasswordChangeDialog()
{
    delete ui;
}
void PasswordChangeDialog::on_pushOk_clicked()
{
    QSqlDatabase::database().open();
    QSqlQuery query;
    query.prepare("select password_hash from CUSTOMER where customer_id = :cust_id");
    query.bindValue(":cust_id", customer_id);
    query.exec();
    query.next();
    if (query.value(0).toString() != ui->lineEdit_oldp->text())
    {
        QMessageBox::warning(this, "Wrong password", "Entered password is not correct");
        QSqlDatabase::database().close();
        return;
    }
    if (ui->lineEdit_newp->text() != ui->lineEdit_rnewp->text())
    {
        QMessageBox::warning(this, "Passwords dont match", "New passwords don't match");
        QSqlDatabase::database().close();
        return;
    }
    QSqlQuery query1;
    query1.prepare("update customer set password_hash = :new_password where customer_id = :cust_id");
    query1.bindValue(":new_password", ui->lineEdit_newp->text());
    query1.bindValue(":cust_id", customer_id);
    query1.exec();
    accept();
    QSqlDatabase::database().close();
}

void PasswordChangeDialog::on_pushCancel_clicked()
{
    reject();
}
