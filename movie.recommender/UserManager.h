#pragma once
#include <vector>
#include <string>
#include "user.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& u);
    void printAllUsers() const;
    User* findUserById(int id);
};