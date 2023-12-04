

#include <fstream>
#include "CustomersRepo.h"


CustomersRepo::CustomersRepo() {
    if (customers.empty()) {
        std::string line;

        std::ifstream fileCust("..\\data\\customers.txt");
        Customer customer;
        while (!fileCust.eof()) {
            std::getline(fileCust, line, ';');
            if (line.empty()) {
                break;
            }
            customer.setId(std::stoi(line));

            std::getline(fileCust, line, ';');
            customer.setName(line);

            std::getline(fileCust, line, ';');
            customer.setLogin(line);

            std::getline(fileCust, line, ';');
            customer.setPassword(line);

            std::getline(fileCust, line, ';');
            customer.setMailAddress(line);

            std::getline(fileCust, line, '\n');
            customer.setPhoneNumber(line);

            customers[customer.getLogin()] = customer;
        };
        fileCust.close();

        std::ifstream fileOrd("..\\data\\orders.txt");
        Order order;
        std::string login;
        while (!fileOrd.eof()) {
            std::getline(fileOrd, line, ';');
            if (line.empty()) {
                break;
            }

            // read user login
            std::getline(fileOrd, login, ';');

            std::getline(fileOrd, line, ';');
            order.setStatus(status.at(line));

            std::getline(fileOrd, line, '\n');
            order.setDeliveryAddress(line);

            customers[login].addOrder(order);
        };
        fileOrd.close();

    }
}

std::unordered_map<std::string, Customer> CustomersRepo::getCustomers() {
    return customers;
}

bool CustomersRepo::contains(const std::string &login) {
    return customers.count(login) != 0;
}

Customer CustomersRepo::getCustomer(const std::string& login) {
    return customers.at(login);
}

void CustomersRepo::addOrder(const std::string& login, Order order) {
    customers.at(login).addOrder(order);
};
