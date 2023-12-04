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
// ������� ��� ������ ���������� � ��������

void customerApp(Customer customer, BooksRepo booksRepo, CustomersRepo& customersRepo) {
    std::string action;

    while (true) {
        std::cout << "///////////////////////////////////\n"
                  << "��� ������ �������� �������:\n"
                  << "1 - ���������� ������ ���� � �������\n"
                  << "2 - ������� �����\n"
                  << "3 - ���������� ������� �������\n"
                  << "4 - ���������� ��������� �����\n"
                  << "///////////////////////////////////\n";
        std::getline(std::cin, action);
        std::cout << "\n";
        if (!is_number(action)) {
            std::cout << "������������ ����\n";
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
                std::cout << "������������ ����\n";
        }
        std::cout << "\n";
    }
}


// 1 - ���������� ������ ���� � �������


// 2 - ������� �����
void createOrder(Customer &customer, const BooksRepo &booksRepo, CustomersRepo customersRepo) {
    std::vector<Book> booksInOrder;
    Order order = Order(booksInOrder);
    std::string choice;
    while (choice != "�") {
        order.addBook(chooseBook(booksRepo));
        while (true) {
            std::cout << "���������� ����� ����? (�/�): ";
            std::getline(std::cin, choice);
            if (choice != "�" && choice != "�") {
                std::cout << "������������ ����\n";
            } else {
                break;
            }
        }
    }

    std::string address;
    std::cout << "������� ����� ��������: ";
    std::getline(std::cin, address);
    order.setDeliveryAddress(address);

    customersRepo.addOrder(customer.getLogin(), order);

    std::cout << "����� ������� ������!\n";
}

Book chooseBook(BooksRepo booksRepo) {
    std::string title;
    std::string strNum;
    int num;
    Book book;

    while (true) {
        std::cout << "\n�������� �����: ";
        std::getline(std::cin, title);
        if (!booksRepo.contains(title)) {
            std::cout << "\n��� ����� �����";
        } else {
            book = booksRepo.getBook(title);
            break;
        }
    }

    while (true) {
        std::cout << "�������� ���������� ����� ���� ��� ������ (�������� " << book.getNumber() << "):";
        std::getline(std::cin, strNum);
        num = stoi(strNum);
        if (book.getNumber() < num) {
            std::cout << "��� ������ ���������� ���� � �������";
        } else {
            break;
        }
    }

    booksRepo.changeNumber(title, num);

    return booksRepo.getBook(title);
}

// 3 - ���������� ������� �������
void viewOrdersHistory(const Customer &customer) {
    std::cout << "��� ������:\n";
    if (customer.getOrders().empty()) {
        std::cout << "������ �����������\n";
    } else {
        for (auto &order: customer.getOrders()) {
            std::cout << order << "\n";
        }
    }

}

// 4 - ���������� ��������� �����
void viewLastOrder(const Customer &customer) {
    std::cout << "��������� �����:\n";
    if (customer.getOrders().empty()) {
        std::cout << "������ �����������\n";
    } else {
        std::cout << customer.getOrders().back() << "\n";
    }
}