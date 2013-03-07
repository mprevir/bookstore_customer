#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QCheckBox>
#include <QtSql>
#include <QMessageBox>
#include <QTableWidget>
#include "book.h"
#include "usersetting.h"
#include <QSettings>
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
    void login_dialog();
    void tableWidget_deleteAll(QTableWidget* tWidget);
    void clear_all_tables();
    ~MainWindow();

    QSqlDatabase db ;
    
public slots:

//    void clicked_tableWidget3_row_delete(int x, int y);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_account_clicked();

    void on_tableWidget_3_cellClicked(int row, int column);

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
