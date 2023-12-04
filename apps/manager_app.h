

#ifndef BOOK_SHOP_MANAGER_APP_H
#define BOOK_SHOP_MANAGER_APP_H

#include <string>
#include <unordered_map>
#include "../model/Book.h"
#include "../model/People/Manager.h"
#include "../repositories/BooksRepo.h"

void managerApp(const Manager &manager, BooksRepo &booksRepo);

void changeNumber(BooksRepo &booksRepo, const Manager &manager);

void deleteBook(BooksRepo &booksRepo, const Manager &manager);

void addBook(BooksRepo &booksRepo, const Manager &manager);

#endif //BOOK_SHOP_MANAGER_APP_H
