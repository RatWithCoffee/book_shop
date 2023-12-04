

#ifndef BOOK_SHOP_CUSTOMERSREPO_H
#define BOOK_SHOP_CUSTOMERSREPO_H


#include <string>
#include <unordered_map>
#include "../model/People/Customer.h"

class CustomersRepo {
    std::unordered_map<std::string, Customer> customers = {};
    const std::unordered_map<std::string, OrderStatus> status = {{"PROCESSING", OrderStatus::PROCESSING},
                                                           {"IN_DELIVER", OrderStatus::IN_DELIVER},
                                                           {"DELIVERED", OrderStatus::DELIVERED}};
public:
    CustomersRepo();

    std::unordered_map<std::string, Customer> getCustomers();
    bool contains(const std::string& login);
    Customer getCustomer(const std::string& login);
    void addOrder(const std::string& login, Order order);

};


#endif //BOOK_SHOP_CUSTOMERSREPO_H
