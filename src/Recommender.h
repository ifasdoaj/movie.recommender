#pragma once
#include <vector>
#include "movie_manager.h"
#include "rating_manager.h"
#include "SimilarityCalculator.h"

class Recommender {
private:
    MovieManager& movieManager;
    RatingManager& ratingManager;

public:
    Recommender(MovieManager& mm, RatingManager& rm);

    std::vector<int> recommend(int userId, int n = 5) const;
    std::vector<int> findSimilarUsers(int userId, int k) const;
};
