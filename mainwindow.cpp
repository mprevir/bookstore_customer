#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QDebug>
#include <QSettings>

//#include <QOCIDriver>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QRadioButton *purch_button = new QRadioButton("Purchase", ui->tableWidget_3);
//    ui->tableWidget_3->setCellWidget(0,5,new QCheckBox(ui->tableWidget_3));
//    ui->tableWidget_3->setCellWidget(0,6, new QPushButton("Delete", ui->tableWidget_3));

    this->setFixedSize(685, 468);
    ui->centralWidget->setVisible(false);

    if(!QSqlDatabase::isDriverAvailable("QOCI"))
    {
    qFatal("Driver not loaded");
    qDebug()<<"oops";
    }

    QSettings settings( "settings.ini", QSettings::IniFormat );

    settings.beginGroup( "database" );

    db = QSqlDatabase::addDatabase( settings.value( "driver", "QOCI" ).toString() );
    db.setHostName( settings.value( "hostname", "localhost" ).toString() );
    db.setDatabaseName( settings.value( "database", "previrpc").toString() );
    db.setUserName( settings.value( "user", "previrpc").toString() );
    db.setPassword( settings.value( "password", "aaaa").toString() );
    bool ok = db.open();

    qDebug()<<ok;
    qDebug()<<db.lastError();

    login* Login = new login(this);
    Login->addMW(this);
    Login->show();

}

void MainWindow::setUsername(QString usern) {
    username = usern;
    ui->label->setText(username);
}

void MainWindow::dbget_Book() {
    QSqlQuery query;
    Book* tBook;
    QString tISBN;
    int tPublisherID;
    QString tTitle;
    float tPrice;
    int tQuantity;

    query.exec("SELECT title, price, quantity, ISBN, publisher_ID FROM BOOK");
    while (query.next()) {
        tTitle = query.value(0).toString();
        tPrice = query.value(1).toFloat();
        tQuantity = query.value(2).toInt();
        tISBN = query.value(3).toString();
        tPublisherID = query.value(4).toInt();
        tBook = new Book(tTitle, tPrice, tQuantity, tISBN, tPublisherID);
        book_vector.push_back(*tBook);
    }
}

void MainWindow::populate_table() {
    std::vector<Book>::iterator tBook;
    for (tBook = book_vector.begin(); tBook != book_vector.end(); tBook++)
    {
        qDebug()<<tBook->getTitle();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        add_table_item(ui->tableWidget->rowCount()-1, 1, tBook->getTitle());
        add_table_item(ui->tableWidget->rowCount()-1, 2, tBook->getISBN());
        add_table_item(ui->tableWidget->rowCount()-1, 3, QString().sprintf("%.2f", tBook->getPrice()));

        QTableWidgetItem* item = new QTableWidgetItem(0);
        QFont font( "Bavaria" ); font.setBold(true); font.setPointSize( 12 );
        item->setFont(font);
        item->setText("Add to cart");
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, item);
    }
    add_table_item(0, 0, "John R.R. Tolkien");
    add_table_item(1, 0, "John R.R. Tolkien");
    add_table_item(2, 0, "Hunter Thompson");
    add_table_item(3, 0, "Herbert Wells");


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
    int curRow = ui->tableWidget_3->rowCount();
    QPushButton del_button("Delete", ui->tableWidget_3);
    ui->tableWidget_3->insertRow(curRow);
    ui->tableWidget_3->setCellWidget(curRow,4,new QCheckBox(ui->tableWidget_3));
    ui->tableWidget_3->setCellWidget(curRow, 5, &del_button);
//    ui->tableWidget_3->setCellWidget(curRow,5, new QPushButton("Delete", ui->tableWidget_3));
    QObject::connect(&del_button, SIGNAL(clicked()), ui->tableWidget_3, SLOT(on_tableWidget3_row_delete));
}

void MainWindow::on_tableWidget3_row_delete(int row)
{

}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
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
//    QMessageBox::warning(0,"Adding to cart", "Under construction");

}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(0, "Searching", "It's not the book you are looking for");
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(0, "Warning", "Insufficient funds");
}
