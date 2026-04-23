#pragma once
#include <vector>
#include "user.h"

class user_manager {
private:
    std::vector<User> users;

public:
    void add_user_direct(const User& u);
    void add_user();
    void print_all() const;
};