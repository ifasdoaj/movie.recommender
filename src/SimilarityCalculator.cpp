#include "SimilarityCalculator.h"
#include <cstdlib>

using namespace std;

int SimilarityCalculator::calculate(const vector<Rating>& ratingsA,
                                     const vector<Rating>& ratingsB) {
    double similarity = 0.0;

    for (const auto& ra : ratingsA) {
        for (const auto& rb : ratingsB) {
            if (ra.getMovieId() == rb.getMovieId()) {
                similarity += 1.0 / (1.0 + abs(ra.getScore() - rb.getScore()));
            }
        }
    }

    return (int)(similarity * 100);
}
