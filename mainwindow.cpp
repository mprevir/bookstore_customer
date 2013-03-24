#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>
#include "usersetting.h"
//#include <QOCIDriver>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    booksModel( new QSqlQueryModel( this ) ),
    booksItem( new QItemSelectionModel( booksModel, this ) ),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_Books->setModel(booksModel);
    ui->tableView_Books->setSelectionModel(booksItem);
    this->setFixedSize(685, 468);

    if(!QSqlDatabase::isDriverAvailable("QOCI"))
    {
    qFatal("Driver not loaded");
    qDebug()<<"oops";
    }

    //    login_dialog();
    QSettings settings ( "settings.ini", QSettings::IniFormat );

    settings.beginGroup( "database" );


    db = QSqlDatabase::addDatabase( settings.value( "driver", "QOCI" ).toString() );
    db.setHostName( settings.value( "hostname", "localhost" ).toString() );
    db.setDatabaseName( settings.value( "database", "previrpc").toString() );
    db.setUserName( settings.value( "user", "previrpc").toString() );
    db.setPassword( settings.value( "password", "aaaa").toString() );
    qDebug()<<"database is open - "<<db.open();
    qDebug()<<db.lastError();
    dbget_Book();
}

void MainWindow::login_dialog()
{
    if (db.isOpen())
    {
        db.close();
        book_vector.clear();
    }
    ui->centralWidget->setVisible(false);
    login* Login = new login(this);
    Login->addMW(this);
    db.open();
    Login->show();
}

void MainWindow::setUsername(QString usern) {
    username = usern;
    ui->label->setText(username);
}

void MainWindow::dbget_Book() {
    QSqlQuery query;
    /*Book* tBook;
    QString tAuthor;
    QString tISBN;
    int tPublisherID;
    QString tTitle;
    float tPrice;
    int tQuantity;*/

    query.prepare("SELECT title, price, quantity, b.ISBN, publisher_ID, name FROM BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id");

    bool qOk = query.exec();
    booksModel->setQuery(query);
    qDebug() << "ASDFSDGFAD" <<  booksModel->rowCount();
}

void MainWindow::populate_books()
{
    /*std::vector<Book>::iterator tBook;
    unsigned i;
    for (tBook = book_vector.begin(), i=0; tBook != book_vector.end() || i<10; tBook++, i++)
    {
        qDebug()<<tBook->getTitle();
        booksModel->
    }*/
}

//    add_table_item(0, 0, "John R.R. Tolkien");
//    add_table_item(1, 0, "John R.R. Tolkien");
//    add_table_item(2, 0, "Hunter Thompson");
//    add_table_item(3, 0, "Herbert Wells");




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(0, "Searching", "It's not the book you are looking for");
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(0, "Warning", "Insufficient funds");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Delete all items from cart?");
    msgBox.addButton(QMessageBox::Ok); msgBox.addButton(QMessageBox::Cancel);
    int status = msgBox.exec();

}



void MainWindow::on_pushButton_account_clicked()
{
    UserSetting userSett(this);
    userSett.exec();
    if (userSett.get_exit_status())
    {
        userSett.close();
        login_dialog();
    } else userSett.close();
}
