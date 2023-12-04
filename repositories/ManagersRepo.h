

#ifndef BOOK_SHOP_MANAGERSREPO_H
#define BOOK_SHOP_MANAGERSREPO_H


#include <string>
#include <unordered_map>
#include "../model/People/Manager.h"

class ManagersRepo {
    std::unordered_map<std::string, Manager> managers = {};
public:
    ManagersRepo();

    std::unordered_map<std::string, Manager> getManagers();
    bool contains(const std::string& login);
    Manager getManager(const std::string& login);

};


#endif //BOOK_SHOP_MANAGERSREPO_H
