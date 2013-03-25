#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
    
    bool alreadyExists();
public:
    explicit RegisterDialog(QWidget *parent = 0);
    QString newLogin;
    QString newPassword;
    QString newEmail;
    QString newPhone;
    ~RegisterDialog();
    
private slots:
    void on_button_Ok_clicked();
    void on_button_Cancel_clicked();

private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
