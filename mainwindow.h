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
#include <QSortFilterProxyModel>
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
    QSortFilterProxyModel* booksProxyModel;
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
    void add_book_to_cart(int row_index);
    void delete_book_from_cart(int row_index);
    int current_customer_ID;
    int current_book_page;
public:
    void update_tableView_Cart();

    void setCurrent_customer_ID(int ID) {current_customer_ID = ID;}
    int getCurrent_customer_ID() {return current_customer_ID;}
    explicit MainWindow(QWidget *parent = 0);
    bool openDB();
    void closeDB();
    void dbget_Book();
    void setUsername(QString usern);
    void login_dialog();
    ~MainWindow();

    
public slots:

//    void clicked_tableWidget3_row_delete(int x, int y);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_account_clicked();

    void on_tableView_Books_clicked(const QModelIndex &index);

    void on_tableView_Cart_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    std::vector<Book> book_vector;
    QString username;
};

#endif // MAINWINDOW_H
