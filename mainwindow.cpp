#define BOOKS_CLICKABLE_COLUMN 4
#define BUNDLES_CLICKABLE_COLUMN 4
#define CART_CLICKABLE_COLUMN 4

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>
#include "usersetting.h"
#include "bundleinfo.h"
//#include <QOCIDriver>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    booksModel( new QSqlQueryModel( this ) ),
    bundlesModel(new QSqlQueryModel(this)),
    cartModel(new QSqlQueryModel(this)),
    historyModel(new QSqlQueryModel(this)),
    booksItem( new QItemSelectionModel( booksModel, this ) ),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_Books->setModel(booksModel);
    ui->tableView_Bundles->setModel(bundlesModel);
    ui->tableView_Cart->setModel(cartModel);
    ui->tableView_History->setModel(historyModel);
    this->setFixedSize(685, 492);

    current_customer_ID = 1;
    current_book_page = 0;
    if(!QSqlDatabase::isDriverAvailable("QOCI"))
    {
    qFatal("Driver not loaded");
    qDebug()<<"oops";
    }

    QSettings settings ( "settings.ini", QSettings::IniFormat );

    settings.beginGroup( "database" );

    databaseDriver = settings.value( "driver", "QOCI" ).toString();
    databaseHost = settings.value( "hostname", "localhost" ).toString();
    databaseName = settings.value( "database", "orcl").toString();
    databaseUser = settings.value( "user", "system").toString();
    databasePassword = settings.value( "password", "orcl").toString();
    databasePort = settings.value("port", 1521).toUInt();
    /*databaseDriver = settings.value( "driver" ).toString();
    databaseHost = settings.value( "hostname" ).toString();
    databaseName = settings.value( "database").toString();
    databaseUser = settings.value( "user").toString();
    databasePassword = settings.value( "password").toString();*/

    qDebug()<<"\nDriver"<<databaseDriver;
    qDebug()<<"Host"<<databaseHost;
    qDebug()<<"Name"<<databaseName;
    qDebug()<<"User"<<databaseUser;
    qDebug()<<"Password"<<databasePassword;
    qDebug()<<"Port"<<databasePort<<"\n";

    QSqlDatabase db = QSqlDatabase::addDatabase( databaseDriver );
    db.setHostName( databaseHost );
    db.setDatabaseName(databaseName );
    db.setUserName( databaseUser );
    db.setPassword( databasePassword );
    db.setPort(databasePort);

    login_dialog();
//    update_tableView_Bundles();
//    update_tableView_Cart();
//    update_tableView_History();
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
    qDebug()<<"database is opened - "<<openDB();
    qDebug()<<QSqlDatabase::database().lastError();
    QSqlQuery query;
//select
//    query.prepare("SELECT title, name, price, b.ISBN, 'Add to cart' FROM BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id");
//select+concat
//    query.prepare("select title, wm_concat(a.name), price, b.ISBN, 'Add to cart' "
//                  "from BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id group by title, price, b.ISBN");

//select+concat+from lowvalue to highvalue
    query.prepare("select title, new_name, price, ISBN, 'Add to cart' from"
                  "("
                    "select row_number() over(order by title) NUM,  title, new_name, price, ISBN, 'Add to cart' from"
                    "("
                        "select title, wm_concat(a.name) as new_name, price, b.ISBN, 'Add to cart'"
                        "from BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id group by title, price, b.ISBN"
                        ") asdf"
                  ") foo where Num>:lowvalue and Num<:highvalue");

    query.bindValue(":lowvalue", current_book_page*10);
    query.bindValue(":highvalue", 10 + current_book_page*10);
    bool qOk = query.exec();
    qDebug()<<"main Query - "<<qOk;
    qDebug()<<"Last error"<< query.lastError();
    booksModel->setQuery(query);
    max_book_pages = booksModel->rowCount() / 10;
    ui->label_page_count->setText(QString("Page %1 out of %2").arg(1).arg(max_book_pages + 1));
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

    return QSqlDatabase::database().open();
}

void MainWindow::closeDB()
{
   QSqlDatabase::database().close();
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()   //search
{
    openDB();
    QSqlQuery query;
    query.prepare("select title, new_name, price, ISBN, 'Add to cart' from "
                  "( "
                    "select row_number() over(order by title) NUM,  title, new_name, price, ISBN, 'Add to cart' from "
                    "( "
                        "select title, wm_concat(a.name) as new_name, price, b.ISBN, 'Add to cart' "
                        "from BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id "
                        "where (lower(b.title) LIKE lower(:search1)) or (lower(a.name) LIKE lower(:search2)) or (lower(b.isbn) LIKE lower(:search3)) "
                        "group by title, price, b.ISBN "
                     ") asdf "
                  ") foo where Num>:lowvalue and Num<:highvalue");
    QString searchCriteria(ui->lineEdit->text());
    searchCriteria = '%' + searchCriteria + '%';
    qDebug()<<"What to search?: "<<searchCriteria;
    query.bindValue(":search1", searchCriteria);
    query.bindValue(":search2", searchCriteria);
    query.bindValue(":search3", searchCriteria);
    query.bindValue(":lowvalue", current_book_page*10);
    query.bindValue(":highvalue", 10+current_book_page*10);
    qDebug()<<"search query: "<<query.exec();
    qDebug()<<query.lastError();
    booksModel->setQuery(query);
    qDebug()<<"rows count: "<<booksModel->rowCount();

    closeDB();
}

void MainWindow::on_pushButton_3_clicked()   //buy
{
    openDB();
    QSqlQuery query;
    query.prepare("select wallet from customer where customer_id = :id");
    query.bindValue(":id", current_customer_ID);
    qDebug()<<"purchase |wallet| query exec: "<<query.exec();
    qDebug()<<query.lastError();
    query.next();
    double wallet = query.value(0).toDouble();
    QSqlQuery query1;
    query1.prepare("select sum(price) from cart");
    query1.exec();
    query1.next();
    double price = query1.value(0).toDouble();
    closeDB();
    if (wallet < price)
        QMessageBox::information(0, "Warning", "Insufficient funds");
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Buy all books in the cart?");
        msgBox.addButton(QMessageBox::Ok); msgBox.addButton(QMessageBox::Cancel);
        int status = msgBox.exec();
        if (status == QMessageBox::Ok)
        {
            openDB();
            QSqlQuery queryBuy;
            queryBuy.prepare("call BUY_CART(:cust_id)");
            queryBuy.bindValue(":cust_id", current_customer_ID);
            qDebug()<<"Buy cart: "<<queryBuy.exec();
            qDebug()<<queryBuy.lastError();
            closeDB();
            update_wallet();
            clear_Cart();
            update_tableView_History();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()  //clear cart
{
    QMessageBox msgBox;
    msgBox.setText("Delete all items from cart?");
    msgBox.addButton(QMessageBox::Ok); msgBox.addButton(QMessageBox::Cancel);
    int status = msgBox.exec();
    qDebug()<<"status = "<<status;
    if (status == QMessageBox::Ok)
    {
        clear_Cart();
    }
}



void MainWindow::on_pushButton_account_clicked()
{
    UserSetting userSett(this, current_customer_ID);
//    userSett.set_current_customer_id(current_customer_ID);
    qDebug()<<"before Current ID: "<<userSett.get_current_customer_id();
    userSett.exec();
    userSett.close();
    update_wallet();
    if (!userSett.get_exit_status())
    {
        login_dialog();
    }
}

void MainWindow::clear_Cart()
{
    openDB();
    QSqlQuery query;
    query.prepare("delete from cart");
    qDebug()<<"Clear cart: "<<query.exec();
    qDebug()<<query.lastError();
    update_tableView_Cart();
    closeDB();
}

void MainWindow::add_book_to_cart(int row_index)
{
    openDB();
    QSqlQuery query;
    query.prepare("call ADD_BOOK_TO_CART(:isbn, :customerID, null, null)");
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

void MainWindow::update_tableView_Books()
{
    openDB();
    QSqlQuery query;
    query.prepare("select title, new_name, price, ISBN, 'Add to cart' from"
                  "("
                    "select row_number() over(order by title) NUM,  title, new_name, price, ISBN, 'Add to cart' from"
                    "("
                        "select title, wm_concat(a.name) as new_name, price, b.ISBN, 'Add to cart'"
                        "from BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id group by title, price, b.ISBN"
                        ") asdf"
                  ") foo where Num>:lowvalue and Num<:highvalue");

    query.bindValue(":lowvalue", current_book_page*10);
    query.bindValue(":highvalue", 10 + current_book_page*10);
    query.exec();
    booksModel->setQuery(query);
    booksModel->setHeaderData( 0, Qt::Horizontal, QObject::tr("Title") );
    booksModel->setHeaderData( 1, Qt::Horizontal, QObject::tr("Author") );
    booksModel->setHeaderData( 2, Qt::Horizontal, QObject::tr("Price") );
    booksModel->setHeaderData( 3, Qt::Horizontal, QObject::tr("Isbn") );
    booksModel->setHeaderData( BOOKS_CLICKABLE_COLUMN, Qt::Horizontal, QObject::tr("") );
    closeDB();
}

void MainWindow::update_tableView_Bundles()
{
    openDB();
    QSqlQuery query;
    query.prepare("select name, ttl, asd1.bundle_id, trunc(prc,2), 'Add to cart' "
                  "from "
                  "( "
                    "select bundle.name, wm_concat(book.title) ttl, bundle.bundle_id "
                    "from bundle, bundledbook, book "
                    "where book.isbn = bundledbook.isbn "
                    "group by bundle.name, bundle.bundle_id "
                  ") asd1 "
                  "join "
                  "( "
                    "select sum((1-discount)*price) prc, bundle.bundle_id "
                    "from bundle, bundledbook, book "
                    "where book.isbn = bundledbook.isbn and bundle.deleted != 1 "
                    "group by bundle.bundle_id "
                  ") asd2 "
                  "on asd1.bundle_id = asd2.bundle_id");
    qDebug()<<"bundles update: "<<query.exec();
    qDebug()<<query.lastError();
    bundlesModel->setQuery(query);
    qDebug()<<"rows found: "<<bundlesModel->rowCount()<<"\n";
    bundlesModel->setHeaderData( 0, Qt::Horizontal, QObject::tr("Bundle"));
    bundlesModel->setHeaderData( 1, Qt::Horizontal, QObject::tr("Books in bundle"));
    bundlesModel->setHeaderData( 2, Qt::Horizontal, QObject::tr("Bundle ID"));
    bundlesModel->setHeaderData( 3, Qt::Horizontal, QObject::tr("Price"));
    bundlesModel->setHeaderData( 4, Qt::Horizontal, QObject::tr(""));
    ui->tableView_Bundles->hideColumn(2);
    closeDB();
}

void MainWindow::update_tableView_Cart()
{
    openDB();
    QSqlQuery query;
//doesn't involve discounts:

    query.prepare("select title, wm_concat(author.name), isbn, cart.price, 'Delete' "
                  "from cart join book on cart.isbn = book.isbn "
                    "join book_s_author ba on  ba.isbn = book.isbn "
                        "join author on ba.author_ID = author.AUTHOR_ID "
                  "where cart.customer_id = :cust_id "
                  "group by title, isbn, cart.price");
    query.bindValue(":cust_id", current_customer_ID);
/*    query.prepare("select asd1.title, asd1.auth_name, asd1.isbn, nvl(asd2.discount, asd1.price), 'Delete' "
                  "from (select title, wm_concat(author.name) auth_name, book.isbn, price, cart.bundle_id "
                                  "from cart join book on cart.isbn = book.isbn "
                                    "join book_s_author ba on  ba.isbn = book.isbn "
                                        "join author on ba.author_ID = author.AUTHOR_ID "
                                  "group by title, book.isbn, price, cart.bundle_id) asd1 "
                "left outer join "
                  "(select discount, isbn, bundle_id "
                      "from bundledbook) asd2 "
                "on asd1.isbn = asd2.isbn and asd1.bundle_id = asd2.bundle_id");*/
    qDebug()<<"TableView updated: "<<query.exec();
    qDebug()<<query.lastError();
    cartModel->setQuery(query);
    ui->label_page_count->setText(QString("Page %1 out of %2").arg(current_book_page + 1).arg(max_book_pages + 1));
    cartModel->setHeaderData( 0, Qt::Horizontal, QObject::tr("Title") );
    cartModel->setHeaderData( 1, Qt::Horizontal, QObject::tr("Author") );
    cartModel->setHeaderData( 2, Qt::Horizontal, QObject::tr("ISBN") );
    cartModel->setHeaderData( 3, Qt::Horizontal, QObject::tr("Price") );
    cartModel->setHeaderData( 4, Qt::Horizontal, QObject::tr(""));
    closeDB();
}

void MainWindow::update_tableView_History()
{
    openDB();
    QSqlQuery query;
    query.prepare("select title, wm_concat(author.name), h.isbn, h.price, to_char(h.purchasing_date, 'DD-MON-YYYY HH24:MI') "
                  "from book join history_of_purchasing h ON book.isbn = h.isbn "
                    "join book_s_author on book.isbn = book_s_author.isbn "
                      "join author on author.author_id = book_s_author.author_id "
                  "where h.customer_id = :cust_id "
                  "group by title, h.isbn, h.price, h.purchasing_date order by h.purchasing_date desc");
    query.bindValue(":cust_id", current_customer_ID);
    qDebug()<<"update HoP: "<<query.exec();
    qDebug()<<query.lastError();
    historyModel->setQuery(query);
    historyModel->setHeaderData( 0, Qt::Horizontal, QObject::tr("Title") );
    historyModel->setHeaderData( 1, Qt::Horizontal, QObject::tr("Author") );
    historyModel->setHeaderData( 2, Qt::Horizontal, QObject::tr("ISBN") );
    historyModel->setHeaderData( 3, Qt::Horizontal, QObject::tr("Price") );
    historyModel->setHeaderData( 4, Qt::Horizontal, QObject::tr("Purchase date"));
    closeDB();
}

void MainWindow::update_wallet()
{
    openDB();
    QSqlQuery query;
    query.prepare("select wallet from customer where customer_id = :id");
    query.bindValue(":id", current_customer_ID);
    qDebug()<<"update_wallet query exec: "<<query.exec();
    qDebug()<<query.lastError();
    query.next();
    double wallet = query.value(0).toDouble();
    closeDB();
    ui->label_2->setText(QString::number(wallet, 'f', 2) + '$');
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

void MainWindow::add_bundle_to_cart(int row_index)
{
    openDB();
    QSqlQuery query;
    query.prepare("call ADD_BUNDLE_TO_CART(:customer_id, :bundle_id)");
    QModelIndex index = bundlesModel->index(row_index, 2);
    QString value_bundle_id = bundlesModel->itemData(index)[0].toString();
    query.bindValue(":customer_id", current_customer_ID);
    query.bindValue(":bundle_id", value_bundle_id);
    qDebug()<<"add bundle to cart: "<<query.exec();
    qDebug()<<query.lastError();
    closeDB();
    update_tableView_Cart();
}

void MainWindow::on_tableView_Bundles_clicked(const QModelIndex &index)
{
    if (index.column() == BUNDLES_CLICKABLE_COLUMN)
        add_bundle_to_cart(index.row());
}

void MainWindow::on_pushButton_Prev_clicked()
{
    if (current_book_page > 0)
    {
        --current_book_page;
        ui->label_page_count->setText(QString("Page %1 out of %2").arg(1).arg(max_book_pages + 1));
        update_tableView_Books();
    }
}

void MainWindow::on_pushButton_Next_clicked()
{
    if (current_book_page < max_book_pages)
    {
        ++current_book_page;
        ui->label_page_count->setText(QString("Page %1 out of %2").arg(1).arg(max_book_pages + 1));
        update_tableView_Books();
    }
}


void MainWindow::on_tableView_Bundles_doubleClicked(const QModelIndex &index)
{
    if (index.column() == BUNDLES_CLICKABLE_COLUMN)
        return;
    QModelIndex bundle_id_index = bundlesModel->index(index.row(), 2); //index of bundle_id item (column 2)
    const int bundle_id = bundlesModel->itemData(bundle_id_index)[0].toInt();
    BundleInfo bundleInfo(bundle_id);
    int status = bundleInfo.exec();
    qDebug()<<"\nBundle Info status: "<<status;
    if (status)
        add_bundle_to_cart(index.row());
}
