

#include "BooksRepo.h"
#include <iostream>
#include <fstream>

void BooksRepo::addBook(const Book& book) {
    std::ofstream file(fileName, std::ios::app);
    book.writeToFile(file);
    books[book.getTitle()] = book;
    file.close();
}

void BooksRepo::deleteBook(const std::string& title) {
    books.erase(title);
    std::ofstream file(fileName, std::ios::trunc);
    for (const auto& pair : books) {
        pair.second.writeToFile(file);
        std::cout << pair.second << std::endl;
    }
    file.close();
}

void BooksRepo::changeNumber(const std::string& title, int newNum) {
    books[title].setNumber(newNum);
    std::ofstream file(fileName, std::ios::trunc);
    for (const auto& pair : books) {
        pair.second.writeToFile(file);
    }
    file.close();
}

bool BooksRepo::contains(const std::string &title) {
    return books.count(title) != 0;
}

void BooksRepo::printAllBooks() {
    std::cout << "Список книг в наличии:\n";
    for (const auto &pair: books) {
        std::cout << pair.second << "\n";
    }
}

Book BooksRepo::getBook(std::string title) {
    return books.at(title);
}

BooksRepo::BooksRepo() {
    if (books.empty()) {
        std::string line;
        std::ifstream file(fileName);
        Book book;

        while (!file.eof()) {
            std::getline(file, line, ';');
            if (line.empty()) {
                break;
            }
            book.setTitle(line);

            std::getline(file, line, ';');
            book.setAuthorName(line);

            std::getline(file, line, ';');
            book.setNumber(stoi(line));

            std::getline(file, line);
            book.setPrice(stoi(line));

            books[book.getTitle()] = book;

        };
        file.close();

    }

}

