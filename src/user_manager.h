#pragma once
#include <vector>
#include <string>
#include "user.h"
#include "BaseManager.h"

class UserManager : public BaseManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& u);
    void findByName(const std::string& name) const;
    void printAll() const;
    User* findById(int id);

    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) const override;
    int size() const override { return users.size(); }
};
