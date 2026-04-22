#include "user_manager.h"
#include <iostream>

using namespace std;

void UserManager::addUser(const User& u) {
    users.push_back(u);
}

void UserManager::printAllUsers() const {
    if (users.empty()) {
        cout << "등록된 사용자가 없습니다." << endl;
        return;
    }
    for (size_t i = 0; i < users.size(); ++i) {
        users[i].display();
    }
}

void UserManager::searchByName(const string& name) const {
    bool found = false;
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].getName() == name) {
            users[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "해당 이름의 사용자를 찾을 수 없습니다." << endl;
    }
}