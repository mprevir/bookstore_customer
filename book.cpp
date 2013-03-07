#include "book.h"

Book::Book()
{
    ISBN = "0000000000";
    publisherID = 0;
    title = "A";
    price = 0.00;
    quantity = -1;
}

Book::Book(QString nAuthor, QString nTitle, float nPrice, int nQuantity, QString nISBN, int nPublisherID) {
    author = nAuthor;
    ISBN = nISBN;
    publisherID = nPublisherID;
    title = nTitle;
    price = nPrice;
    quantity = nQuantity;
}

void Book::setAuthor(QString nAuthor)
{
    author = nAuthor;
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

QString Book::getAuthor()
{
    return author;
}

QString Book::getTitle()
{
    return title;
}

QString Book::getISBN()
{
    return ISBN;
}

float Book::getPrice()
{
    return price;
}
