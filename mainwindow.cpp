#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>
#include "usersetting.h"
//#include <QOCIDriver>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(685, 468);

    if(!QSqlDatabase::isDriverAvailable("QOCI"))
    {
    qFatal("Driver not loaded");
    qDebug()<<"oops";
    }

    login_dialog();
    QSettings settings ( "settings.ini", QSettings::IniFormat );

    settings.beginGroup( "database" );


    db = QSqlDatabase::addDatabase( settings.value( "driver", "QOCI" ).toString() );
    db.setHostName( settings.value( "hostname", "localhost" ).toString() );
    db.setDatabaseName( settings.value( "database", "previrpc").toString() );
    db.setUserName( settings.value( "user", "previrpc").toString() );
    db.setPassword( settings.value( "password", "aaaa").toString() );
    bool ok = db.open();
    qDebug()<<db.lastError();
}

void MainWindow::login_dialog()
{
    if (db.isOpen())
    {
        db.close();
        book_vector.clear();
        clear_all_tables();
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
    Book* tBook;
    QString tAuthor;
    QString tISBN;
    int tPublisherID;
    QString tTitle;
    float tPrice;
    int tQuantity;

    bool qOk = query.exec("SELECT title, price, quantity, b.ISBN, publisher_ID, name FROM BOOK b INNER JOIN BOOK_S_AUTHOR ba on b.ISBN = ba.ISBN INNER JOIN AUTHOR a on ba.author_id = a.author_id");
    qDebug()<<qOk;
    while (query.next()) {

        tTitle = query.value(0).toString();
        tPrice = query.value(1).toFloat();
        tQuantity = query.value(2).toInt();
        tISBN = query.value(3).toString();
        tPublisherID = query.value(4).toInt();
        tAuthor = query.value(5).toString();
        tBook = new Book(tAuthor, tTitle, tPrice, tQuantity, tISBN, tPublisherID);
        book_vector.push_back(*tBook);
    }
}

void MainWindow::populate_table() {
    std::vector<Book>::iterator tBook;
    for (tBook = book_vector.begin(); tBook != book_vector.end(); tBook++)
    {
        qDebug()<<tBook->getTitle();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        add_table_item(ui->tableWidget->rowCount()-1, 0, tBook->getAuthor());
        add_table_item(ui->tableWidget->rowCount()-1, 1, tBook->getTitle());
        add_table_item(ui->tableWidget->rowCount()-1, 2, tBook->getISBN());
        add_table_item(ui->tableWidget->rowCount()-1, 3, QString().sprintf("%.2f", tBook->getPrice()));

        QTableWidgetItem* item = new QTableWidgetItem(0);
        QFont font( "Bavaria" ); font.setBold(true); font.setPointSize( 12 );
        item->setFont(font);
        item->setText("Add to cart");
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, item);
    }
//    add_table_item(0, 0, "John R.R. Tolkien");
//    add_table_item(1, 0, "John R.R. Tolkien");
//    add_table_item(2, 0, "Hunter Thompson");
//    add_table_item(3, 0, "Herbert Wells");


}

void MainWindow::add_table_item(int x, int y, QString text) {
    QTableWidgetItem* item = new QTableWidgetItem(0);
    item->setText(text);
    ui->tableWidget->setItem(x, y, item);
}

void MainWindow::add_table3_item(int x, int y, QString text) {
    QTableWidgetItem* item = new QTableWidgetItem(0);
    item->setText(text);
    ui->tableWidget_3->setItem(x, y, item);
}

void MainWindow::add_table_item(int x, int y, QTableWidgetItem *item) {
    QTableWidgetItem* newItem = new QTableWidgetItem;
    newItem->setText(item->text());
    ui->tableWidget->setItem(x, y, newItem);
}

void MainWindow::add_table3_item(int x, int y, QTableWidgetItem *item) {
    QTableWidgetItem* newItem = new QTableWidgetItem;
    newItem->setText(item->text());
    ui->tableWidget_3->setItem(x, y, newItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRowTableWidget_3()
{
    const int curRow = ui->tableWidget_3->rowCount();
    ui->tableWidget_3->insertRow(curRow);
//    QPushButton *del_button = new QPushButton("Delete", ui->tableWidget_3);
    ui->tableWidget_3->setCellWidget(curRow,4,new QCheckBox(ui->tableWidget_3));
    QTableWidgetItem* item = new QTableWidgetItem(0);
    QFont font( "Bavaria" ); font.setBold(true); font.setPointSize( 12 );
    item->setFont(font);
    item->setText("Delete");
    ui->tableWidget_3->setItem(curRow, 5, item);
//    connect(ui->tableWidget_3, SIGNAL(cellClicked(int,int)), this, SLOT(clicked_tableWidget3_row_delete(int, int)));
}

//void MainWindow::clicked_tableWidget3_row_delete(int x, int y)
//{

//    int row_num = ui->tableWidget_3->currentRow();
//    qDebug()<<row_num;
//    ui->tableWidget_3->removeRow(x);
//}


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
    if (status == QMessageBox::Ok)
    {
        tableWidget_deleteAll(ui->tableWidget_3);
    }
}

void MainWindow::tableWidget_deleteAll(QTableWidget* tWidget)
{
//    unsigned row_num = tWidget->rowCount();
//    for (unsigned i=0; i<row_num; i++)
//        tWidget->removeRow(0);
    while(tWidget->rowCount())
        tWidget->removeRow(0);
}

void MainWindow::clear_all_tables()
{
    tableWidget_deleteAll(ui->tableWidget);
    tableWidget_deleteAll(ui->tableWidget_2);
    tableWidget_deleteAll(ui->tableWidget_3);
    tableWidget_deleteAll(ui->tableWidget_4);
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if (column!=4) return;
        else
    {
        addRowTableWidget_3();
        int curRow = ui->tableWidget_3->rowCount()-1;
        int i;
        for (i=0; i<4; i++)
            add_table3_item(curRow, i, ui->tableWidget->item(row, i));
    }
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

void MainWindow::on_tableWidget_3_cellClicked(int row, int column)
{
    if (column!=5) return;
        else
    ui->tableWidget_3->removeRow(row);
}
