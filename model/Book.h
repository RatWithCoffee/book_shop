

#ifndef BOOK_SHOP_BOOK_H
#define BOOK_SHOP_BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    Book();

    Book(std::string title, std::string authorName, int number, double price);
    Book(const Book& other) : title(other.title), authorName(other.authorName), number(other.number), price(other.price) {};

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    [[nodiscard]] int getNumber() const;

    [[nodiscard]] const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void setAuthorName(const std::string &authorName);

    void setPrice(double price);

    void setNumber(int number);

    void writeToFile(std::ofstream& file) const;

private:
    std::string title;
    std::string authorName;
    int number;
    double price;
};


#endif //BOOK_SHOP_BOOK_H
