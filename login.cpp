#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "QDebug.h"
#include <QSqlQuery>
#include "registerdialog.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login window");
    this->setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
    ui->label_3->setVisible(false);
}

login::~login()
{
    delete ui;
}

void login::addMW(MainWindow *MW) {
    this->mainW = MW;
}

#include <QSqlResult>
void login::on_pushButton_Ok_clicked()
{
    const QString entered_login(ui->lineEdit_login->text());
    const QString entered_password(ui->lineEdit_password->text());
    QString correct_password;

    bool connection_established = mainW->openDB();
    if (!connection_established)
    {
        QMessageBox::information(0, "Connection problem", "Cannot connect to server.\n"
                                 "Check your connection settings (settings.ini - located in program folder)");
        return;
    }
    QSqlQuery query;
    query.prepare("select password_hash, customer_id from CUSTOMER where name = :login");
    query.bindValue(":login", entered_login);
    qDebug()<<"query exec"<<query.exec();
    qDebug()<<"query.next - "<<query.next();
    if (query.isNull(0))
    {
        ui->label_3->setVisible(true);
        return;
    }
    correct_password = query.value(0).toString();
    qDebug()<<"password: "<<correct_password;
    mainW->setCurrent_customer_ID(query.value(1).toInt());
    qDebug()<<"customer ID: "<< mainW->getCurrent_customer_ID();
    mainW->closeDB();

    if (entered_password == correct_password)
    {
        this->setVisible(false);
        mainW->centralWidget()->setVisible(true);
        mainW->dbget_Book();
        mainW->setUsername(ui->lineEdit_login->text());
        mainW->update_wallet();

    } else ui->label_3->setVisible(true);
}

void login::on_pushButton_Register_clicked()
{
    RegisterDialog regDialog(this);
//    qDebug()<<"dialog returned: "<<regDialog.exec();
    mainW->openDB();
    if (regDialog.exec())
    {
        QSqlQuery query;
        query.prepare("call CUSTOMER_INSERT(:login, :email, :phone, :password)");
        query.bindValue(":login", regDialog.newLogin);
        query.bindValue(":email", regDialog.newEmail);
        query.bindValue(":phone", regDialog.newPhone);
        query.bindValue(":password", regDialog.newPassword);
        qDebug()<<"customer_insert exec: "<<query.exec();
        qDebug()<<"last error:"<<query.lastError();
    }
    mainW->closeDB();
}

void login::on_pushButton_2_clicked()
{
    mainW->close();
}
