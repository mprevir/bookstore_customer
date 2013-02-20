#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    Book(QString nTitle, float nPrice, int nQuantity, QString nISBN, int nPublisherID);

    QString getISBN();
    int getPublisherID();
    QString getTitle();
    float getPrice();
    int getQuantity();

    void setISBN(QString nISBN);
    void setPublisherID(int nPublisherID);
    void setTitle(QString nTitle);
    void setPrice(float nPrice);
    void setQuantity(int nQuantity);
private:
    QString ISBN;
    int publisherID;
    QString title;
    float price;
    int quantity;
};

#endif // BOOK_H
