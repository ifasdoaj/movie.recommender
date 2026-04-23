#include "user_manager.h"
#include <iostream>

using namespace std;

void user_manager::add_user_direct(const User& u) {
    users.push_back(u);
}

void user_manager::add_user() {
    int id;
    string name, email;
    cout << "사용자 ID: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    cin.ignore(1000, '\n');
    cout << "이름: "; getline(cin, name);
    cout << "이메일: "; getline(cin, email);
    users.push_back(User(id, name, email));
}

void user_manager::print_all() const {
    if (users.empty()) {
        cout << "등록된 사용자가 없습니다." << endl;
        return;
    }
    for (const auto& u : users) u.display();
}