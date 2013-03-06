#include "usersetting.h"
#include "ui_usersetting.h"

UserSetting::UserSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSetting)
{
    ui->setupUi(this);
}

UserSetting::~UserSetting()
{
    delete ui;
}

void UserSetting::on_closeButton_clicked()
{
    exit_status = 0;
    close();
}

void UserSetting::on_logoutButton_clicked()
{
    exit_status = 1;
    close();
}
