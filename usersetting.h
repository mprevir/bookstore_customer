#ifndef USERSETTING_H
#define USERSETTING_H

#include <QDialog>

namespace Ui {
class UserSetting;
}

class UserSetting : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserSetting(QWidget *parent = 0);
    int get_exit_status() {return exit_status;}
    ~UserSetting();
    
private slots:
    void on_closeButton_clicked();

    void on_logoutButton_clicked();

private:
    int exit_status; //0 - closed, 1 - loged out
    Ui::UserSetting *ui;
};

#endif // USERSETTING_H
