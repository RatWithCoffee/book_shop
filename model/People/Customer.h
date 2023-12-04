

#ifndef BOOK_SHOP_CUSTOMER_H
#define BOOK_SHOP_CUSTOMER_H


#include "Human.h"
#include "../Order/Order.h"
#include <vector>

class Customer : public Human {
public:
    Customer(int id, const std::string &name, const std::string &login, const std::string &password,
             const std::string &mailAddress, std::string phoneNumber, const std::vector<Order> &orders);
    Customer();
    [[nodiscard]] int getId() const override;

    void setPhoneNumber(const std::string &phoneNumber);

    void setOrders(const std::vector<Order> &orders);

    [[nodiscard]] const std::vector<Order> &getOrders() const;
    void addOrder(const Order& order);

private:
    std::string phoneNumber;
    std::vector<Order> orders;

};


#endif //BOOK_SHOP_CUSTOMER_H
