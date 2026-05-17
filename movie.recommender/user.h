#pragma once
#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User();
    User(int uId, std::string uName, std::string uEmail);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;

    void display() const;
};