

#ifndef BOOK_SHOP_BOOKSREPO_H
#define BOOK_SHOP_BOOKSREPO_H


#include <string>
#include <unordered_map>
#include "../model/Book.h"

class BooksRepo {
    std::unordered_map<std::string, Book> books = {};
    const std::string fileName = "..\\data\\books.txt";

public:
    BooksRepo();
    void addBook(const Book& book);
    void deleteBook(const std::string& title);
    void changeNumber(const std::string& title, int newNum);
    bool contains(const std::string& title);
    void printAllBooks();
    Book getBook(std::string title);
};


#endif //BOOK_SHOP_BOOKSREPO_H
