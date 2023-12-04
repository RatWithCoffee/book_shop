
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
                  << "Для выбора действия нажмите:\n"
                  << "1 - посмотреть список книг в наличии\n"
                  << "2 - добавить новую книгу\n"
                  << "3 - удалить книгу\n"
                  << "4 - изменить количество книг\n"
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
                addBook(booksRepo, manager);
                break;
            case 3:
                deleteBook(booksRepo, manager);
                break;
            case 4:
                changeNumber(booksRepo, manager);
                break;
            default:
                std::cout << "Неправильный ввод\n";
        }
        std::cout << "\n";
    }


}

void changeNumber(BooksRepo &booksRepo, const Manager &manager) {
    if (!manager.getRights().changeNumOfBook) {
        std::cout << "У вас недостаточно прав";
        return;
    }

    std::string title;
    std::cout << "Введите название книги: ";
    std::getline(std::cin, title);

    if (!booksRepo.contains(title)) {
        std::cout << "\nНет такой книги";
        return;
    }

    std::string strNum;
    while (true) {
        std::cout << "\nВведите количество книг: ";
        std::getline(std::cin, strNum);
        if (!is_number(strNum)) {
            std::cout << "Неправильный ввод\n";
        } else {
            booksRepo.changeNumber(title, stoi(strNum));
            break;
        }
    }

    std::cout << "Количество книг было изменено";
}

void deleteBook(BooksRepo &booksRepo, const Manager &manager) {
    if (!manager.getRights().deleteBook) {
        std::cout << "У вас недостаточно прав";
        return;
    }

    std::string title;
    std::cout << "Введите название книги: ";
    std::getline(std::cin, title);

    booksRepo.deleteBook(title);

    std::cout << "Книга была удалена";
}

void addBook(BooksRepo &booksRepo, const Manager &manager) {
    if (!manager.getRights().addBook) {
        std::cout << "У вас недостаточно прав";
        return;
    }

    std::string buff;
    Book book = Book();

    std::cout << "Введите название книги: ";
    std::getline(std::cin, buff);
    book.setTitle(buff);

    std::cout << "Введите имя автора: ";
    std::getline(std::cin, buff);
    book.setAuthorName(buff);

    while (true) {
        std::cout << "Введите количество книг: ";
        std::getline(std::cin, buff);
        if (!is_number(buff)) {
            std::cout << "Неправильный ввод\n";
        } else {
            book.setNumber(stoi(buff));
            break;
        }
    }

    while (true) {
        std::cout << "Введите стоимость книги: ";
        std::getline(std::cin, buff);
        if (!is_number(buff)) {
            std::cout << "Неправильный ввод\n";
        } else {
            book.setPrice(stoi(buff));
            break;
        }
    }

    booksRepo.addBook(book);

    std::cout << "Книга была добавлена";
}



