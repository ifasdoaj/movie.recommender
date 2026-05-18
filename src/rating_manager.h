#pragma once
#include <vector>
#include <string>
#include "rating.h"
#include "BaseManager.h"

class RatingManager : public BaseManager {
private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& r);
    void printByMovieId(int mId) const;
    void printByUserId(int uId) const;
    void printAll() const;

    std::vector<Rating> findByUser(int userId) const;
    std::vector<int> getAllUserIds() const;
    std::vector<Rating> getAll() const;

    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) const override;
    int size() const override { return ratings.size(); }
};
