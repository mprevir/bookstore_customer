#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QCheckBox>
#include <QtSql>
//#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void setUsername(QString usern);
    void populate_database(); //no need for this, so far
    ~MainWindow();
    
private slots:


private:
    Ui::MainWindow *ui;
    QString username;
};

#endif // MAINWINDOW_H
