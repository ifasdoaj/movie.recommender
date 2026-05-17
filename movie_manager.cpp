#include "movie_manager.h"
#include <iostream>
#include <algorithm>

using namespace std;

MovieManager::MovieManager(RatingManager& rm, UserManager& um) : ratingManager(rm), userManager(um) {}

void MovieManager::addMovie(const Movie& m) {
    movies.push_back(m);
}

void MovieManager::addMovieByUser(int userId) {
    if (!userManager.findById(userId)) {
        cout << "존재하지 않는 사용자 ID입니다." << endl;
        return;
    }
    int id, year;
    string title, genre;
    cout << "ID: "; cin >> id;
    cin.ignore(1000, '\n');
    cout << "제목: "; getline(cin, title);
    cout << "장르: "; getline(cin, genre);
    cout << "연도: "; cin >> year;
    movies.push_back(Movie(id, title, genre, year, userId));
    cout << "영화가 추가되었습니다." << endl;
}

void MovieManager::findByTitle(const string& title) const {
    bool found = false;
    for (const auto& m : movies) {
        if (m.getTitle().find(title) != string::npos) {
            cout << m << endl;
            found = true;
        }
    }
    if (!found) cout << "해당 제목의 영화를 찾을 수 없습니다." << endl;
}

void MovieManager::printAll() const {
    if (movies.empty()) {
        cout << "등록된 영화가 없습니다." << endl;
        return;
    }
    for (const auto& m : movies) cout << m << endl;
}

void MovieManager::sortByRating() {
    if (movies.empty()) {
        cout << "등록된 영화가 없습니다." << endl;
        return;
    }
    vector<Movie> sortedMovies = movies;
    sort(sortedMovies.begin(), sortedMovies.end(), [](const Movie& a, const Movie& b) {
        return a.getAverageRating() > b.getAverageRating();
    });
    for (const auto& m : sortedMovies) cout << m << endl;
}

void MovieManager::addRatingToMovie(int mId, int uId, double score) {
    for (auto& m : movies) {
        if (m.getId() == mId) {
            ratingManager.addRating(Rating(uId, mId, score));
            m.addRating(score);
            return;
        }
    }
    cout << "해당 ID의 영화를 찾을 수 없습니다." << endl;
}

void MovieManager::printRatingsByMovieId(int mId) const {
    ratingManager.printByMovieId(mId);
}

Movie* MovieManager::findById(int id) {
    for (auto& m : movies) {
        if (m.getId() == id) return &m;
    }
    return nullptr;
}
