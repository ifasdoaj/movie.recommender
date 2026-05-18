#include "rating_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void RatingManager::addRating(const Rating& r) {
    ratings.push_back(r);
}

void RatingManager::printByMovieId(int mId) const {
    bool found = false;
    for (const auto& r : ratings) {
        if (r.getMovieId() == mId) {
            r.display();
            found = true;
        }
    }
    if (!found) cout << "해당 영화 ID의 평점 내역이 없습니다." << endl;
}

void RatingManager::printByUserId(int uId) const {
    bool found = false;
    for (const auto& r : ratings) {
        if (r.getUserId() == uId) {
            r.display();
            found = true;
        }
    }
    if (!found) cout << "해당 사용자 ID의 평점 내역이 없습니다." << endl;
}

void RatingManager::printAll() const {
    if (ratings.empty()) {
        cout << "등록된 평점이 없습니다." << endl;
        return;
    }
    for (const auto& r : ratings) r.display();
}

vector<Rating> RatingManager::findByUser(int userId) const {
    vector<Rating> result;
    for (const auto& r : ratings) {
        if (r.getUserId() == userId) result.push_back(r);
    }
    return result;
}

vector<int> RatingManager::getAllUserIds() const {
    vector<int> ids;
    for (const auto& r : ratings) {
        bool exists = false;
        for (int id : ids) {
            if (id == r.getUserId()) { exists = true; break; }
        }
        if (!exists) ids.push_back(r.getUserId());
    }
    return ids;
}

// ↓ 추가된 함수
vector<Rating> RatingManager::getAll() const {
    return ratings;
}

void RatingManager::loadFromFile(const string& filename) {
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
        getline(ss, token, ','); int userId = stoi(token);
        getline(ss, token, ','); int movieId = stoi(token);
        getline(ss, token, ','); double score = stod(token);
        ratings.push_back(Rating(userId, movieId, score));
    }
    file.close();
    cout << filename << " 로드 완료: " << ratings.size() << "건" << endl;
}

void RatingManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    file << "userId,movieId,score" << endl;
    for (const auto& r : ratings) {
        file << r.getUserId() << ","
             << r.getMovieId() << ","
             << r.getScore() << endl;
    }
    file.close();
    cout << filename << " 저장 완료: " << ratings.size() << "건" << endl;
}
