#include <iostream>
#include <string>
#include "movie.h"
#include "user.h"
#include "rating.h"
#include "movie_manager.h"
#include "user_manager.h"

using namespace std;

void showMenu() {
    cout << "\n===== 영화 추천 시스템 =====" << endl;
    cout << "1. 영화 추가" << endl;
    cout << "2. 모든 영화 출력 (평점순)" << endl;
    cout << "3. 영화 제목 검색" << endl;
    cout << "4. 사용자 추가" << endl;
    cout << "5. 모든 사용자 출력" << endl;
    cout << "6. 사용자 이름 검색" << endl;
    cout << "0. 종료" << endl;
    cout << "선택: ";
}

int main() {
    MovieManager movieMgr;
    UserManager userMgr;

    userMgr.addUser(User(20252811, "방현민", "bhmin0217@gmail.com"));
    userMgr.addUser(User(20250001, "김철수", "chulsoo@example.com"));
    userMgr.addUser(User(20250002, "이영희", "younghee@example.com"));
    
    Movie m1(1, "그것만이 내세상", "코미디", 2018);
    m1.addRating(5.0);
    m1.addRating(4.0);
    m1.addRating(4.5);
    movieMgr.addMovie(m1);

    Movie m2(2, "식스센스", "스릴러", 1999);
    m2.addRating(5.0);
    m2.addRating(4.8);
    m2.addRating(9.9); 
    movieMgr.addMovie(m2);

    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            string discard;
            getline(cin, discard);
            continue;
        }

        if (choice == 0) break;

        if (choice == 1) {
            int id, year;
            string title, genre;
            cout << "ID: "; cin >> id;
            cin.ignore();
            cout << "제목: "; getline(cin, title);
            cout << "장르: "; getline(cin, genre);
            cout << "개봉연도: "; cin >> year;
            movieMgr.addMovie(Movie(id, title, genre, year));
        } 
        else if (choice == 2) {
            movieMgr.sortByRating();
            movieMgr.printAllMovies();
        } 
        else if (choice == 3) {
            string title;
            cin.ignore();
            cout << "검색할 제목: "; getline(cin, title);
            movieMgr.searchByTitle(title);
        } 
        else if (choice == 4) {
            int id;
            string name, email;
            cout << "ID(학번): "; cin >> id;
            cin.ignore();
            cout << "이름: "; getline(cin, name);
            cout << "이메일: "; getline(cin, email);
            userMgr.addUser(User(id, name, email));
        } 
        else if (choice == 5) {
            userMgr.printAllUsers();
        } 
        else if (choice == 6) {
            string name;
            cin.ignore();
            cout << "검색할 이름: "; getline(cin, name);
            userMgr.searchByName(name);
        }
    }

    return 0;
}