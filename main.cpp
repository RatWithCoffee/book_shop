#include <iostream>
#include <unordered_map>
#include <windows.h>
#include "model/Book.h"
#include "model/People/Customer.h"
#include "model/People/Manager.h"
#include "apps/customer_app.h"
#include "apps/manager_app.h"
#include "repositories/BooksRepo.h"
#include "repositories/CustomersRepo.h"
#include "repositories/ManagersRepo.h"


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BooksRepo booksRepo = BooksRepo();
    CustomersRepo customersRepo = CustomersRepo();
    ManagersRepo managersRepo = ManagersRepo();

    std::string login;
    std::string password;

    while (true) {
        std::cout << "Войдите в аккаунт\n";
        std::cout << "Логин: ";
        std::getline(std::cin, login);
        std::cout << "Пароль: ";
        std::getline(std::cin, password);
        if (customersRepo.contains(login)) {
            while (true) {
                if (customersRepo.getCustomer(login).getPassword() == password) {
                    std::cout << "Вход в систему...\n";
                    customerApp(customersRepo.getCustomer(login), booksRepo, customersRepo);
                    break;
                } else {
                    std::cout << "Неверный пароль. Попробуйте еще раз\n";
                    std::cout << "Пароль: ";
                    std::getline(std::cin, password);
                }

            }
        } else if (managersRepo.contains(login)) {
            while (true) if (managersRepo.getManager(login).getPassword() == password) {
                    std::cout << "Вход в систему...\n";
                    managerApp(managersRepo.getManager(login), booksRepo);
                    break;
                } else {
                    std::cout << "Неверный пароль. Попробуйте еще раз\n";
                    std::cout << "Пароль: ";
                    std::getline(std::cin, password);
                }
        } else {
            std::cout << "Вы не зарегестрированы в системе\n";
        }
    }
}



