#include "user.h"
#include <iostream>

using namespace std;

User::User() : id(0), name(""), email("") {}

User::User(int uId, string uName, string uEmail) 
    : id(uId), name(uName), email(uEmail) {}

int User::getId() const { return id; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }

void User::display() const {
    cout << "ID: " << id << "\tName: " << name << "\tEmail: " << email << endl;
}