#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>
#include "../model/Book.h"
#include "../model/People/Customer.h"
#include "../model/People/Manager.h"
#include "customer_app.h"
#include "utils.h"
#include "../repositories/BooksRepo.h"
#include "../repositories/CustomersRepo.h"
// функции для работы приложения с клиентом

void customerApp(Customer customer, BooksRepo booksRepo, CustomersRepo& customersRepo) {
    std::string action;

    while (true) {
        std::cout << "///////////////////////////////////\n"
                  << "Для выбора действия нажмите:\n"
                  << "1 - посмотреть список книг в наличии\n"
                  << "2 - сделать заказ\n"
                  << "3 - посмотреть историю заказов\n"
                  << "4 - посмотреть последний заказ\n"
                  << "///////////////////////////////////\n";
        std::getline(std::cin, action);
        std::cout << "\n";
        if (!is_number(action)) {
            std::cout << "Неправильный ввод\n";
            continue;
        }
        switch (stoi(action)) {
            case 1:
                booksRepo.printAllBooks();
                break;
            case 2:
                createOrder(customer, booksRepo, customersRepo);
                break;
            case 3:
                viewOrdersHistory(customer);
                break;
            case 4:
                viewLastOrder(customer);
                break;
            default:
                std::cout << "Неправильный ввод\n";
        }
        std::cout << "\n";
    }
}


// 1 - посмотреть список книг в наличии


// 2 - сделать заказ
void createOrder(Customer &customer, const BooksRepo &booksRepo, CustomersRepo customersRepo) {
    std::vector<Book> booksInOrder;
    Order order = Order(booksInOrder);
    std::string choice;
    while (choice != "н") {
        order.addBook(chooseBook(booksRepo));
        while (true) {
            std::cout << "Продолжить выбор книг? (д/н): ";
            std::getline(std::cin, choice);
            if (choice != "д" && choice != "н") {
                std::cout << "Неправильный ввод\n";
            } else {
                break;
            }
        }
    }

    std::string address;
    std::cout << "Укажите адрес доставки: ";
    std::getline(std::cin, address);
    order.setDeliveryAddress(address);

    customersRepo.addOrder(customer.getLogin(), order);

    std::cout << "Заказ успешно сделан!\n";
}

Book chooseBook(BooksRepo booksRepo) {
    std::string title;
    std::string strNum;
    int num;
    Book book;

    while (true) {
        std::cout << "\nВыберите книгу: ";
        std::getline(std::cin, title);
        if (!booksRepo.contains(title)) {
            std::cout << "\nНет такой книги";
        } else {
            book = booksRepo.getBook(title);
            break;
        }
    }

    while (true) {
        std::cout << "Выберите количество таких книг для заказа (доступно " << book.getNumber() << "):";
        std::getline(std::cin, strNum);
        num = stoi(strNum);
        if (book.getNumber() < num) {
            std::cout << "Нет такого количества книг в наличии";
        } else {
            break;
        }
    }

    booksRepo.changeNumber(title, num);

    return booksRepo.getBook(title);
}

// 3 - посмотреть историю заказов
void viewOrdersHistory(const Customer &customer) {
    std::cout << "Все заказы:\n";
    if (customer.getOrders().empty()) {
        std::cout << "Заказы отсутствуют\n";
    } else {
        for (auto &order: customer.getOrders()) {
            std::cout << order << "\n";
        }
    }

}

// 4 - посмотреть последний заказ
void viewLastOrder(const Customer &customer) {
    std::cout << "Последний заказ:\n";
    if (customer.getOrders().empty()) {
        std::cout << "Заказы отсутствуют\n";
    } else {
        std::cout << customer.getOrders().back() << "\n";
    }
}