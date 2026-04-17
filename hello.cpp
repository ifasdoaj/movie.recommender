#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "=== 영화 추천 시스템 ===" << endl;
    cout << "이름 입력: ";
    getline(cin, name);
    cout << name << "님, 환영합니다!" << endl;
    return 0;
} 
