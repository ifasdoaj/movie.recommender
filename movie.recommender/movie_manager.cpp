#include "movie_manager.h"
#include <iostream>
#include <algorithm>

using namespace std;

void MovieManager::addMovie(const Movie& m) {
    movies.push_back(m);
}

void MovieManager::searchByTitle(const string& t) {
    bool found = false;
    for (auto& m : movies) {
        if (m.getTitle() == t) {
            m.display();
            found = true;
        }
    }
    if (!found) cout << "해당 제목의 영화를 찾을 수 없습니다." << endl;
}

void MovieManager::printAllMovies() const {
    if (movies.empty()) {
        cout << "등록된 영화가 없습니다." << endl;
        return;
    }
    for (const auto& m : movies) m.display();
}

void MovieManager::sortByRatingAndPrint() {
    if (movies.empty()) return;
    vector<Movie> sortedMovies = movies;
    sort(sortedMovies.begin(), sortedMovies.end());
    for (const auto& m : sortedMovies) m.display();
}

void MovieManager::addRatingToMovie(int mId, int uId, double score) {
    for (auto& m : movies) {
        if (m.getId() == mId) {
            ratings.push_back(Rating(uId, mId, score));
            m.addRating(score);
            return;
        }
    }
    cout << "해당 ID의 영화를 찾을 수 없습니다." << endl;
}

void MovieManager::printRatingsByMovieId(int mId) const {
    bool found = false;
    for (const auto& r : ratings) {
        if (r.getMovieId() == mId) {
            cout << "사용자 ID: " << r.getUserId() << " | 평점: " << r.getScore() << endl;
            found = true;
        }
    }
    if (!found) cout << "해당 영화에 대한 평점이 없습니다." << endl;
}