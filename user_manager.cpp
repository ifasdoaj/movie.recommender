#include "user_manager.h"
#include <iostream>

using namespace std;

void UserManager::addUser(const User& u) {
    users.push_back(u);
}

void UserManager::findByName(const string& name) const {
    bool found = false;
    for (const auto& u : users) {
        if (u.getName().find(name) != string::npos) {
            u.display();
            found = true;
        }
    }
    if (!found) cout << "해당 이름의 사용자를 찾을 수 없습니다." << endl;
}

void UserManager::printAll() const {
    if (users.empty()) {
        cout << "등록된 사용자가 없습니다." << endl;
        return;
    }
    for (const auto& u : users) u.display();
}

User* UserManager::findById(int id) {
    for (auto& u : users) {
        if (u.getId() == id) return &u;
    }
    return nullptr;
}
