#include "rating_manager.h"
#include <iostream>

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
    if (!found) {
        cout << "해당 영화 ID의 평점 내역이 없습니다." << endl;
    }
}

void RatingManager::printByUserId(int uId) const {
    bool found = false;
    for (const auto& r : ratings) {
        if (r.getUserId() == uId) {
            r.display();
            found = true;
        }
    }
    if (!found) {
        cout << "해당 사용자 ID의 평점 내역이 없습니다." << endl;
    }
}

void RatingManager::printAll() const {
    if (ratings.empty()) {
        cout << "등록된 평점이 없습니다." << endl;
        return;
    }
    for (const auto& r : ratings) {
        r.display();
    }
}