
#include "Customer.h"

Customer::Customer(int id, const std::string &name, const std::string &login, const std::string &password,
                   const std::string &mailAddress, std::string phoneNumber, const std::vector<Order> &orders)
        : Human(id, name, login, password, mailAddress), phoneNumber(std::move(phoneNumber)), orders(orders) {}

int Customer::getId() const {
    return 0;
}

const std::vector<Order> &Customer::getOrders() const {
    return orders;
}

Customer::Customer() {

}

void Customer::addOrder(const Order& order) {
    orders.push_back(order);
}

void Customer::setPhoneNumber(const std::string &phoneNumber) {
    Customer::phoneNumber = phoneNumber;
}

void Customer::setOrders(const std::vector<Order> &orders) {
    Customer::orders = orders;
}


#include <utility>
