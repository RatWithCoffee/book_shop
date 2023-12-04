
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include "../model/Book.h"
#include "../model/People/Customer.h"
#include "../model/People/Manager.h"
#include "utils.h"
#include "manager_app.h"

void managerApp(const Manager &manager, BooksRepo& booksRepo) {
    std::string action;

    while (true) {
        std::cout << "///////////////////////////////////\n"
                  << "��� ������ �������� �������:\n"
                  << "1 - ���������� ������ ���� � �������\n"
                  << "2 - �������� ����� �����\n"
                  << "3 - ������� �����\n"
                  << "4 - �������� ���������� ����\n"
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
                addBook(booksRepo, manager);
                break;
            case 3:
                deleteBook(booksRepo, manager);
                break;
            case 4:
                changeNumber(booksRepo, manager);
                break;
            default:
                std::cout << "������������ ����\n";
        }
        std::cout << "\n";
    }


}

void changeNumber(BooksRepo &booksRepo, const Manager &manager) {
    if (!manager.getRights().changeNumOfBook) {
        std::cout << "� ��� ������������ ����";
        return;
    }

    std::string title;
    std::cout << "������� �������� �����: ";
    std::getline(std::cin, title);

    if (!booksRepo.contains(title)) {
        std::cout << "\n��� ����� �����";
        return;
    }

    std::string strNum;
    while (true) {
        std::cout << "\n������� ���������� ����: ";
        std::getline(std::cin, strNum);
        if (!is_number(strNum)) {
            std::cout << "������������ ����\n";
        } else {
            booksRepo.changeNumber(title, stoi(strNum));
            break;
        }
    }

    std::cout << "���������� ���� ���� ��������";
}

void deleteBook(BooksRepo &booksRepo, const Manager &manager) {
    if (!manager.getRights().deleteBook) {
        std::cout << "� ��� ������������ ����";
        return;
    }

    std::string title;
    std::cout << "������� �������� �����: ";
    std::getline(std::cin, title);

    booksRepo.deleteBook(title);

    std::cout << "����� ���� �������";
}

void addBook(BooksRepo &booksRepo, const Manager &manager) {
    if (!manager.getRights().addBook) {
        std::cout << "� ��� ������������ ����";
        return;
    }

    std::string buff;
    Book book = Book();

    std::cout << "������� �������� �����: ";
    std::getline(std::cin, buff);
    book.setTitle(buff);

    std::cout << "������� ��� ������: ";
    std::getline(std::cin, buff);
    book.setAuthorName(buff);

    while (true) {
        std::cout << "������� ���������� ����: ";
        std::getline(std::cin, buff);
        if (!is_number(buff)) {
            std::cout << "������������ ����\n";
        } else {
            book.setNumber(stoi(buff));
            break;
        }
    }

    while (true) {
        std::cout << "������� ��������� �����: ";
        std::getline(std::cin, buff);
        if (!is_number(buff)) {
            std::cout << "������������ ����\n";
        } else {
            book.setPrice(stoi(buff));
            break;
        }
    }

    booksRepo.addBook(book);

    std::cout << "����� ���� ���������";
}



