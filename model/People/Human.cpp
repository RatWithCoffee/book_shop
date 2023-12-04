

#include "Human.h"


Human::Human(int id, std::string name, std::string login, std::string password,
             std::string mailAddress) : id(id), name(std::move(name)), login(std::move(login)),
                                        password(std::move(password)),
                                        mailAddress(std::move(mailAddress)) {}

const std::string &Human::getPassword() const {
    return password;
}

Human::Human() {

}

const std::string &Human::getLogin() const {
    return login;
}

void Human::setId(int id) {
    Human::id = id;
}

void Human::setName(const std::string &name) {
    Human::name = name;
}

void Human::setLogin(const std::string &login) {
    Human::login = login;
}

void Human::setPassword(const std::string &password) {
    Human::password = password;
}

void Human::setMailAddress(const std::string &mailAddress) {
    Human::mailAddress = mailAddress;
}
