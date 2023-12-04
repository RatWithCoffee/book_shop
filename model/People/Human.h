

#ifndef BOOK_SHOP_HUMAN_H
#define BOOK_SHOP_HUMAN_H


#include <string>

class Human {
protected:
    int id;
    std::string name;
    std::string login;
    std::string password;
    std::string mailAddress;

public:
    Human();
    Human(int id, std::string name, std::string login, std::string password,
          std::string mailAddress);

    [[nodiscard]] virtual int getId() const = 0;

    [[nodiscard]] const std::string &getPassword() const;

    void setId(int id);

    void setName(const std::string &name);

    void setLogin(const std::string &login);

    void setPassword(const std::string &password);

    void setMailAddress(const std::string &mailAddress);

    const std::string &getLogin() const;
};


#endif //BOOK_SHOP_HUMAN_H
