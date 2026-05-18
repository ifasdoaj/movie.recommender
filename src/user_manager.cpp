#include "user_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void UserManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: " << filename << " 열 수 없습니다." << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ','); int id = stoi(token);
        getline(ss, token, ','); string name = token;
        getline(ss, token, ','); string email = token;
        users.push_back(User(id, name, email));
    }
    file.close();
    cout << filename << " 로드 완료: " << users.size() << "건" << endl;
}

void UserManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    file << "id,name,email" << endl;
    for (const auto& u : users) {
        file << u.getId() << ","
             << u.getName() << ","
             << u.getEmail() << endl;
    }
    file.close();
    cout << filename << " 저장 완료: " << users.size() << "건" << endl;
}
