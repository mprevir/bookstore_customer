#ifndef USERSETTING_H
#define USERSETTING_H

#include <QDialog>

namespace Ui {
class UserSetting;
}

class UserSetting : public QDialog
{
    Q_OBJECT

    int current_customer_id;
public:
    void set_current_customer_id(int new_id) {current_customer_id = new_id;}
    int get_current_customer_id() {return current_customer_id;}
    explicit UserSetting(QWidget *parent = 0);
    UserSetting(QWidget *parent = 0, int customer_id = -1);
    int get_exit_status() {return exit_status;}
    void update_wallet();
    ~UserSetting();
    
private slots:
    void on_closeButton_clicked();

    void on_logoutButton_clicked();

    void on_pushButton_clicked();

private:
    int exit_status; //0 - closed, 1 - loged out
    Ui::UserSetting *ui;
};

#endif // USERSETTING_H
