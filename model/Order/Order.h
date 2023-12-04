

#ifndef BOOK_SHOP_ORDER_H
#define BOOK_SHOP_ORDER_H


#include "../Book.h"
#include "OrderStatus.h"
#include <map>
#include <vector>

class Order {
    std::vector<Book> books = {};
    OrderStatus status;
    std::string deliveryAddress;

public:
    explicit Order(const std::vector<Book> &books);

    void addBook(const Book &book);

    void setDeliveryAddress(const std::string &deliveryAddress);

    friend std::ostream &operator<<(std::ostream &os, const Order &order);

    Order();

    void setBooks(const std::vector<Book> &books);

    void setStatus(OrderStatus status);
};


#endif //BOOK_SHOP_ORDER_H
