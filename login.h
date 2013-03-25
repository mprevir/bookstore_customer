#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    void addMW(MainWindow* MW);
    ~login();
    
private:
    MainWindow* mainW;

private slots:

    void on_pushButton_Ok_clicked();

    void on_pushButton_Register_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
