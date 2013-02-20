#include "book.h"

Book::Book()
{
    ISBN = "0000000000";
    publisherID = 0;
    title = "A";
    price = 0.00;
    quantity = -1;
}

Book::Book(QString nTitle, float nPrice, int nQuantity, QString nISBN, int nPublisherID) {
    ISBN = nISBN;
    publisherID = nPublisherID;
    title = nTitle;
    price = nPrice;
    quantity = nQuantity;
}

void Book::setISBN(QString nISBN) {
    ISBN = nISBN;
}

void Book::setPublisherID(int nPublisherID) {
    publisherID = nPublisherID;
}

void Book::setTitle(QString nTitle) {
    title = nTitle;
}

void Book::setPrice(float nPrice) {
    price = nPrice;
}

void Book::setQuantity(int nQuantity) {
    quantity = nQuantity;
}

QString Book::getTitle() {
    return title;
}

QString Book::getISBN() {
    return ISBN;
}

float Book::getPrice() {
    return price;
}
