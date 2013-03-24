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
#include <QSqlQueryModel>
#include <QItemSelectionModel>
//#include "login.h"

namespace Ui {
class MainWindow;
}
//TODO: recreate tableView's

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    QSqlQueryModel* booksModel;
    QItemSelectionModel* booksItem;
    QSqlQueryModel* bundlesModel;
    QItemSelectionModel* bundlesItem;
    QSqlQueryModel* cartModel;
    QItemSelectionModel* cartItem;
    QSqlQueryModel* historyModel;
    QItemSelectionModel* historyItem;

    QString databaseDriver;
    QString databaseHost;
    QString databaseName;
    QString databaseUser;
    QString databasePassword;
    void populate_books();
public:
    explicit MainWindow(QWidget *parent = 0);
    bool openDB();
    void closeDB();
    void dbget_Book();
    void setUsername(QString usern);
    void login_dialog();
    ~MainWindow();

    QSqlDatabase db ;
    
public slots:

//    void clicked_tableWidget3_row_delete(int x, int y);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_account_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Book> book_vector;
    QString username;
};

#endif // MAINWINDOW_H
