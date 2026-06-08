#include "movie_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <stdexcept>

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

void MovieManager::syncRatings() {
    for (auto& m : movies) {
        m.resetRatingData();
        for (const auto& r : ratingManager.getAll()) {
            if (r.getMovieId() == m.getId()) {
                m.addRating(r.getScore());
            }
        }
    }
}

double MovieManager::getAverageRating() const {
    if (movies.empty()) {
        throw runtime_error("영화 데이터가 없습니다.");
    }
    double sum = accumulate(movies.begin(), movies.end(), 0.0,
        [](double acc, const Movie& m) {
            return acc + m.getAverageRating();
        });
    return sum / movies.size();
}

map<string, double> MovieManager::getAverageRatingByGenre() const {
    map<string, double> sumByGenre;
    map<string, int> countByGenre;

    for (const auto& m : movies) {
        sumByGenre[m.getGenre()] += m.getAverageRating();
        countByGenre[m.getGenre()]++;
    }

    map<string, double> avgByGenre;
    for (const auto& [genre, sum] : sumByGenre) {
        avgByGenre[genre] = sum / countByGenre[genre];
    }
    return avgByGenre;
}

vector<Movie> MovieManager::getTopN(int n) const {
    vector<Movie> sorted = movies;
    sort(sorted.begin(), sorted.end(), [](const Movie& a, const Movie& b) {
        return a.getAverageRating() > b.getAverageRating();
    });
    if (n > (int)sorted.size()) {
        n = sorted.size();
    }
    return vector<Movie>(sorted.begin(), sorted.begin() + n);
}

void MovieManager::exportStatisticsToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    file << "genre,averageRating" << endl;
    map<string, double> avgByGenre = getAverageRatingByGenre();
    for (const auto& [genre, avg] : avgByGenre) {
        file << genre << "," << avg << endl;
    }
    file.close();
    cout << filename << " 통계 저장 완료" << endl;
}

void MovieManager::loadFromFile(const string& filename) {
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
        getline(ss, token, ','); string title = token;
        getline(ss, token, ','); string genre = token;
        getline(ss, token, ','); int year = stoi(token);
        int userId = 0;
        if (getline(ss, token, ',')) {
            userId = stoi(token);
        }
        movies.push_back(Movie(id, title, genre, year, userId));
    }
    file.close();
    cout << filename << " 로드 완료: " << movies.size() << "건" << endl;
}

void MovieManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    file << "id,title,genre,year,addedByUserId" << endl;
    for (const auto& m : movies) {
        file << m.getId() << ","
             << m.getTitle() << ","
             << m.getGenre() << ","
             << m.getReleaseYear() << ","
             << m.getAddedByUserId() << endl;
    }
    file.close();
    cout << filename << " 저장 완료: " << movies.size() << "건" << endl;
}
