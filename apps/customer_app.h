

#ifndef BOOK_SHOP_CUSTOMER_APP_H
#define BOOK_SHOP_CUSTOMER_APP_H

#include <unordered_map>
#include "../model/Book.h"
#include "../model/People/Customer.h"
#include "../repositories/BooksRepo.h"
#include "../repositories/CustomersRepo.h"


Book chooseBook(BooksRepo booksRepo);
void customerApp( Customer customer, BooksRepo booksRepo, CustomersRepo& customersRepo);
void viewLastOrder(const Customer &customer);
void viewOrdersHistory(const Customer &customer);
void createOrder(Customer &customer, const BooksRepo &booksRepo, CustomersRepo customersRepo);
#endif //BOOK_SHOP_CUSTOMER_APP_H
