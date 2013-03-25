#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
    ui->label_taken->setVisible(false);
    ui->label_er1->setVisible(false);
    ui->label_er2->setVisible(false);
    ui->label_er3->setVisible(false);
    ui->label_erEmail->setVisible(false);
    ui->label_erPhone->setVisible(false);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(on_button_Ok_clicked()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(on_button_Cancel_clicked()));
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_button_Ok_clicked()
{
    bool accept(true);
    newLogin = ui->lineEdit_login->text();
    if (newLogin == "")   //is login blank?
    {
        ui->label_er1->setVisible(true);
        accept = false;
    } else
        ui->label_er1->setVisible(false);

    if (ui->lineEdit_password->text() == "") //is password blank?
    {
        ui->label_er2->setVisible(true);
        accept = false;
    } else
        ui->label_er2->setVisible(false);

    if (ui->lineEdit_password->text() != ui->lineEdit_re_password->text())  //do passwords match?
    {
        ui->label_er3->setVisible(true);
        accept = false;
    } else
    {
        ui->label_er3->setVisible(false);
    }

    if (ui->lineEdit_Email->text() == "") //is email blank?
    {
        ui->label_erEmail->setVisible(true);
        accept = false;
    } else
    {
        ui->label_erEmail->setVisible(false);
        newEmail = ui->lineEdit_Email->text();
    }

    if (ui->lineEdit_Phone->text() == "") //is phone blank
    {
        ui->label_erPhone->setVisible(true);
        accept = false;
    } else
    {
        ui->label_erPhone->setVisible(false);
        newPhone = ui->lineEdit_Phone->text();
    }

    if (alreadyExists())  //does the customer with the same name exist?
    {
        ui->label_taken->setVisible(true);
        accept = false;
    } else
        ui->label_taken->setVisible(false);

    newPassword = ui->lineEdit_password->text();
    if (accept)
        this->accept();
}

void RegisterDialog::on_button_Cancel_clicked()
{
    this->reject();
}

bool RegisterDialog::alreadyExists()
{
    QSqlQuery query;
    query.prepare("select name from CUSTOMER where name = :newLogin");
    query.bindValue(":newLogin", newLogin);
    qDebug()<<"QUERY.EXEC: "<<query.exec();
    qDebug()<<"Last error: "<<query.lastError();
    query.next();
    qDebug()<<"value = "<< query.value(0).toString();
    if (query.isNull(0))
        return false;
           else
        return true;
}
