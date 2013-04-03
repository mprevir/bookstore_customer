#ifndef PASSWORDCHANGEDIALOG_H
#define PASSWORDCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
class PasswordChangeDialog;
}

class PasswordChangeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PasswordChangeDialog(QWidget *parent = 0);
    int customer_id;
    ~PasswordChangeDialog();
    
private slots:
    void on_pushOk_clicked();

    void on_pushCancel_clicked();

private:
    Ui::PasswordChangeDialog *ui;
};

#endif // PASSWORDCHANGEDIALOG_H
