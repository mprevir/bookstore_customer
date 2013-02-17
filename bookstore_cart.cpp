#include "bookstore_cart.h"
#include "ui_bookstore_cart.h"

bookstore_cart::bookstore_cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookstore_cart)
{
    ui->setupUi(this);
}

bookstore_cart::~bookstore_cart()
{
    delete ui;
}
