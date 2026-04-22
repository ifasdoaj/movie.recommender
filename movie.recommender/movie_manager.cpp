#include "movie_manager.h"
#include <iostream>
#include <algorithm>
    

using namespace std;

void MovieManager::addMovie(const Movie& m) {
    movies.push_back(m);
}

void MovieManager::printAllMovies() const {
    if (movies.empty()) {
        cout << "등록된 영화가 없습니다." << endl;
        return;
    }
    for (size_t i = 0; i < movies.size(); ++i) {
        movies[i].display();
    }
}

void MovieManager::sortByRating() {
    sort(movies.begin(), movies.end());
}

void MovieManager::searchByTitle(const string& title) const {
    bool found = false;
    
    Movie targetMovie(0, title, "", 0); 

    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i] == targetMovie) { 
            movies[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "해당 제목의 영화를 찾을 수 없습니다." << endl;
    }
}