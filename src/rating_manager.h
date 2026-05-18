#pragma once
#include <vector>
#include "rating.h"

class RatingManager {
private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& r);
    void printByMovieId(int mId) const;
    void printByUserId(int uId) const;
    void printAll() const;
};