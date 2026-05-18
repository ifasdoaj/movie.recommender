#pragma once
#include <vector>
#include "movie_manager.h"
#include "rating_manager.h"

class Recommender {
private:
    MovieManager& movieManager;
    RatingManager& ratingManager;

public:
    Recommender(MovieManager& mm, RatingManager& rm);

    // 두 유저의 평점 목록을 비교해서 유사도 계산
    int SimilarityCalculate(const std::vector<Rating>& ratingsA,
                            const std::vector<Rating>& ratingsB) const;

    // 유저 ID를 받아서 영화 추천 (상위 n개)
    std::vector<int> recommend(int userId, int n = 5) const;

    // 유사 사용자 찾기 (상위 k명)
    std::vector<int> findSimilarUsers(int userId, int k) const;
};
