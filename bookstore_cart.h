#ifndef BOOKSTORE_CART_H
#define BOOKSTORE_CART_H

#include <QDialog>

namespace Ui {
class bookstore_cart;
}

class bookstore_cart : public QDialog
{
    Q_OBJECT
    
public:
    explicit bookstore_cart(QWidget *parent = 0);
    ~bookstore_cart();
    
private:
    Ui::bookstore_cart *ui;
};

#endif // BOOKSTORE_CART_H
