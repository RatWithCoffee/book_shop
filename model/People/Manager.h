

#ifndef BOOK_SHOP_MANAGER_H
#define BOOK_SHOP_MANAGER_H


#include "Rights.h"
#include "Human.h"

class Manager: public Human {
public:
    Manager();
    Manager(int id, const std::string &name, const std::string &login, const std::string &password,
            const std::string &mailAddress, const Rights &rights);
    [[nodiscard]] int getId() const override;

    const Rights &getRights() const;

    void setRights(const Rights &rights);

private:
    Rights rights;
};


#endif //BOOK_SHOP_MANAGER_H
