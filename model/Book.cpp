
#include <fstream>
#include "Book.h"


Book::Book(std::string title, std::string authorName, int number, double price) : title(std::move(title)),
                                                                                  authorName(std::move(authorName)),
                                                                                  number(number),
                                                                                  price(price) {}



std::ostream &operator<<(std::ostream &os, const Book &book) {
    return os << "Название: " << book.title << " Автор: " << book.authorName << " Стоимость: " << book.price
              << " Количество: " << book.number;
}

int Book::getNumber() const {
    return number;
}


void Book::setNumber(int number) {
    Book::number = number;
}

Book::Book() {

}

const std::string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string &title) {
    Book::title = title;
}

void Book::setAuthorName(const std::string &authorName) {
    Book::authorName = authorName;
}

void Book::setPrice(double price) {
    Book::price = price;
}

void Book::writeToFile(std::ofstream& file) const {
    file << title << ";" << authorName << ";" << number << ";" << price << "\n";
}



