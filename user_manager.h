#pragma once
#include <vector>
#include <string>
#include "user.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& u);
    void findByName(const std::string& name) const;
    void printAll() const;
    User* findById(int id);
};
