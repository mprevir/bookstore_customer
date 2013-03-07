#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    Book(QString nAuthor, QString nTitle, float nPrice, int nQuantity, QString nISBN, int nPublisherID);

    QString getAuthor();
    QString getISBN();
    int getPublisherID();
    QString getTitle();
    float getPrice();
    int getQuantity();

    void setAuthor(QString nAuthor);
    void setISBN(QString nISBN);
    void setPublisherID(int nPublisherID);
    void setTitle(QString nTitle);
    void setPrice(float nPrice);
    void setQuantity(int nQuantity);
private:
    QString author;
    QString ISBN;
    int publisherID;
    QString title;
    float price;
    int quantity;
};

#endif // BOOK_H
