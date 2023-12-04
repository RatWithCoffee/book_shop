

#include "Manager.h"

Manager::Manager(int id, const std::string &name, const std::string &login, const std::string &password,
                 const std::string &mailAddress, const Rights &rights) : Human(id, name, login, password, mailAddress),
                                                                         rights(rights) {}

int Manager::getId() const {
    return 0;
}

Manager::Manager() {

}

const Rights &Manager::getRights() const {
    return rights;
}

void Manager::setRights(const Rights &rights) {
    Manager::rights = rights;
}

