#pragma once
#include <vector>
#include "rating.h"

class SimilarityCalculator {
public:
    static int calculate(const std::vector<Rating>& ratingsA,
                         const std::vector<Rating>& ratingsB);
};
