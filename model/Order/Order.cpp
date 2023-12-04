

#include "Order.h"


Order::Order(const std::vector<Book> &books) {

}

void Order::addBook(const Book &book) {
    books.push_back(book);
}

void Order::setDeliveryAddress(const std::string &deliveryAddress) {
    Order::deliveryAddress = deliveryAddress;
}

std::ostream &operator<<(std::ostream &os, const Order &order) {
//    os << "Книги в заказе:\n";
//    for (auto &b: order.books) {
//        os << b << "\n";
//    }
    return os << "Адрес доставки: " << order.deliveryAddress << "\nСтатус заказа: " << order.status;
}

Order::Order() {

}

void Order::setBooks(const std::vector<Book> &books) {
    Order::books = books;
}

void Order::setStatus(OrderStatus status) {
    Order::status = status;
}

