

#include <fstream>
#include "ManagersRepo.h"

ManagersRepo::ManagersRepo() {
    if (managers.empty()) {
        std::string line;
        std::ifstream file("..\\data\\managers.txt");
        Manager manager;
        while (!file.eof()) {
            std::getline(file, line, ';');
            if (line.empty()) {
                break;
            }
            manager.setId(std::stoi(line));

            std::getline(file, line, ';');
            manager.setName(line);

            std::getline(file, line, ';');
            manager.setLogin(line);

            std::getline(file, line, ';');
            manager.setPassword(line);

            std::getline(file, line, ';');
            manager.setMailAddress(line);

            std::getline(file, line, '\n');
            manager.setRights({bool(line[0]), bool(line[2]), bool(line[4])});

            managers[manager.getLogin()] = manager;
        };
        file.close();
    }
}

std::unordered_map<std::string, Manager> ManagersRepo::getManagers() {
    return managers;
}

Manager ManagersRepo::getManager(const std::string& login) {
    return managers.at(login);
}

bool ManagersRepo::contains(const std::string &login) {
    return managers.count(login) != 0;
};
