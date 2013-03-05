#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QCheckBox>
#include <QtSql>
#include <QMessageBox>
#include <QTableWidget>
#include "book.h"
//#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void dbget_Book();
    void setUsername(QString usern);
    void populate_table();
    void addRowTableWidget_3();
    ~MainWindow();

    QSqlDatabase db ;
    
private slots:


    void on_tableWidget_cellActivated(int row, int column);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Book> book_vector;
    void add_table_item(int x, int y, QString text);
    void add_table3_item(int x, int y, QString text);
    void add_table_item(int x, int y, QTableWidgetItem* item);
    void add_table3_item(int x, int y, QTableWidgetItem* item);
    QString username;
};

#endif // MAINWINDOW_H
