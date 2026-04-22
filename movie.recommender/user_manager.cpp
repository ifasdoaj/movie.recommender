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