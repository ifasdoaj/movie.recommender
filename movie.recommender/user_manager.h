#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "user.h"

class user_manager {
private:
    std::vector<User> users;

public:
    void add_user_direct(const User& u) {
        users.push_back(u);
    }

    void add_user() {
        int id;
        std::string name, email;
        std::cout << "ID: "; std::cin >> id;
        std::cin.ignore(1000, '\n');
        std::cout << "이름: "; std::getline(std::cin, name);
        std::cout << "이메일: "; std::getline(std::cin, email);
        users.push_back(User(id, name, email));
    }

    void print_all() const {
        for (const auto& u : users) u.display();
    }
};