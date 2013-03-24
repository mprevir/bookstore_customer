#define BOOKS_CLICKABLE_COLUMN 4
#define CART_CLICKABLE_COLUMN 4

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>
#include "usersetting.h"
//#include <QOCIDriver>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    booksModel( new QSqlQueryModel( this ) ),
    cartModel(new QSqlQueryModel(this)),
    booksItem( new QItemSelectionModel( booksModel, this ) ),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_Books->setModel(booksModel);
    ui->tableView_Books->setSelectionModel(booksItem);
    ui->tableView_Cart->setModel(cartModel);
    this->setFixedSize(685, 468);

    current_customer_ID = 1;
    if(!QSqlDatabase::isDriverAvailable("QOCI"))
    {
    qFatal("Driver not loaded");
    qDebug()<<"oops";
    }

    QSettings settings ( "settings.ini", QSettings::IniFormat );

    settings.beginGroup( "database" );

    databaseDriver = settings.value( "driver", "QOCI" ).toString();
    databaseHost = settings.value( "hostname", "localhost" ).toString();
    databaseName = settings.value( "database", "previrpc").toString();
    databaseUser = settings.value( "user", "previrpc").toString();
    databasePassword = settings.value( "password", "aaaa").toString();

    login_dialog();
    update_tableView_Cart();
}

void MainWindow::login_dialog()
{
    /*if (db.isOpen())
    {
        db.close();
        book_vector.clear();
    }*/
    ui->centralWidget->setVisible(false);
    login* Login = new login(this);
    Login->addMW(this);
    Login->show();
}

void MainWindow::setUsername(QString usern) {
    username = usern;
    ui->label->setText(username);
}

void MainWindow::dbget_Book() {
    /*Book* tBook;
    QString tAuthor;
    QString tISBN;
    int tPublisherID;
    QString tTitle;
    float tPrice;
    int tQuantity;*/



    qDebug()<<"database is opened - "<<openDB();
    qDebug()<<QSqlDatabase::database().lastError();
    QSqlQuery query;
    query.prepare("SELECT title, name, price, b.ISBN, 'Add to cart' FROM BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id");

    bool qOk = query.exec();
    booksModel->setQuery(query);
    booksModel->setHeaderData( 0, Qt::Horizontal, QObject::tr("Title") );
    booksModel->setHeaderData( 1, Qt::Horizontal, QObject::tr("Author") );
    booksModel->setHeaderData( 2, Qt::Horizontal, QObject::tr("Price") );
    booksModel->setHeaderData( 3, Qt::Horizontal, QObject::tr("Isbn") );
    booksModel->setHeaderData( BOOKS_CLICKABLE_COLUMN, Qt::Horizontal, QObject::tr("") );
    qDebug() << "Rows found: " <<  booksModel->rowCount();
    closeDB();
//     qDebug()<<"database is opened (but it shouldn't be - )"<<QSqlDatabase::database().isOpen();
}

bool MainWindow::openDB()
{
    if (QSqlDatabase::database().isOpen())
    {
//        qDebug()<<"database is already opened";
        return true;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase( databaseDriver );
    db.setHostName( databaseHost );
    db.setDatabaseName(databaseName );
    db.setUserName( databaseUser );
    db.setPassword( databasePassword );
    return db.open();
}

void MainWindow::closeDB()
{
   QSqlDatabase::database().close();
//     qDebug()<<"database is opened (but it shouldn't be - )"<<QSqlDatabase::database().isOpen();
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


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    QSqlQuery testInsert;
//    qDebug() << "Prepare: " << testInsert.prepare( "insert into author( author_id, name ) values"
//                                                   " ( sequence.nextval, :name )");

//    testInsert.bindValue( ":name", "ASFDGHDGJKSF" );

//    qDebug() << "tr: " << QSqlDatabase::database().transaction();
//    qDebug() << "EXEC: " << testInsert.exec() << testInsert.lastError();
//    qDebug() << "LID: " << testInsert.lastInsertId();
//    qDebug() << "Commit: " << QSqlDatabase::database().commit();
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

void MainWindow::add_book_to_cart(int row_index)
{
    openDB();
    QSqlQuery query;
    query.prepare("call ADD_BOOK_TO_CART(:isbn, :customerID, null)");
    QModelIndex index = booksModel->index(row_index, 3);
    QString value3 = booksModel->itemData(index)[0].toString();
    qDebug()<<"ISBN: "<<value3;
    query.bindValue(":isbn", value3);
    query.bindValue(":customerID", current_customer_ID);
    qDebug()<<"book added: "<<query.exec();
    qDebug()<<"error - "<<query.lastError();
    //TODO
    closeDB();
    update_tableView_Cart();

}

void MainWindow::on_tableView_Books_clicked(const QModelIndex &index)
{

    if (index.column() == BOOKS_CLICKABLE_COLUMN)  //"add to cart" pressed
        add_book_to_cart(index.row());
}

void MainWindow::update_tableView_Cart()
{
    openDB();
    QSqlQuery query;
    query.prepare("select title, author.name, isbn, price, 'Delete' "
                  "from cart join book on cart.isbn = book.isbn "
                    "join book_s_author ba on  ba.isbn = book.isbn "
                        "join author on ba.author_ID = author.AUTHOR_ID");
    qDebug()<<"TableView updated: "<<query.exec();
    qDebug()<<query.lastError();
    cartModel->setQuery(query);
    closeDB();
}

void MainWindow::delete_book_from_cart(int row_index)
{
    openDB();
    QSqlQuery query;
    query.prepare("call DELETE_BOOK_FROM_CART(:isbn, :cur_customer_id)");
    QModelIndex index = cartModel->index(row_index, 2);
    QString value_isbn = cartModel->itemData(index)[0].toString();
    query.bindValue(":isbn", value_isbn);
    query.bindValue(":cur_customer_id", current_customer_ID);
    qDebug()<<"delete book from cart: "<<query.exec();
    qDebug()<<query.lastError();
    closeDB();
    update_tableView_Cart();
}

void MainWindow::on_tableView_Cart_clicked(const QModelIndex &index)
{
    if (index.column() == CART_CLICKABLE_COLUMN)
        delete_book_from_cart(index.row());
}
