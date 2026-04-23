#include "movie_manager.h"
#include <iostream>
#include <algorithm>

using namespace std;

void movie_manager::add_movie_direct(const Movie& m) {
    movies.push_back(m);
}

void movie_manager::add_movie() {
    Movie temp;
    if (cin >> temp) {
        movies.push_back(temp);
        cout << "영화가 추가되었습니다." << endl;
    } else {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "잘못된 입력입니다." << endl;
    }
}

void movie_manager::search_by_title() const {
    string title;
    cout << "검색어: ";
    cin.ignore(1000, '\n');
    getline(cin, title);
    bool found = false;
    for (const auto& m : movies) {
        if (m.getTitle().find(title) != string::npos) {
            cout << m << endl;
            found = true;
        }
    }
    if (!found) cout << "검색 결과가 없습니다." << endl;
}

void movie_manager::print_all() const {
    if (movies.empty()) {
        cout << "등록된 영화가 없습니다." << endl;
        return;
    }
    for (const auto& m : movies) cout << m << endl;
}

void movie_manager::sort_and_print() {
    if (movies.empty()) return;
    vector<Movie> sorted = movies;
    sort(sorted.begin(), sorted.end());
    for (const auto& m : sorted) cout << m << endl;
}

Movie* movie_manager::find_by_id(int id) {
    for (auto& m : movies) {
        if (m.getId() == id) return &m;
    }
    return nullptr;
}