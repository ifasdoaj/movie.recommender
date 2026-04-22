#include "UserManager.h"
#include <iostream>

using namespace std;

void UserManager::addUser(const User& u) {
    users.push_back(u);
}

void UserManager::printAllUsers() const {
    cout << "\n[ 전체 사용자 목록 ]" << endl;
    for (const auto& u : users) {
        u.display(); 
    }
}

User* UserManager::findUserById(int id) {
    for (auto& u : users) {
        if (u.getId() == id) {
            return &u;
        }
    }
    return nullptr;
}