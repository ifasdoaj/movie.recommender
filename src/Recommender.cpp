#include "Recommender.h"
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

Recommender::Recommender(MovieManager& mm, RatingManager& rm)
    : movieManager(mm), ratingManager(rm) {}

int Recommender::SimilarityCalculate(const vector<Rating>& ratingsA,
                                      const vector<Rating>& ratingsB) const {
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

vector<int> Recommender::findSimilarUsers(int userId, int k) const {
    vector<Rating> myRatings = ratingManager.findByUser(userId);

    vector<pair<int, int>> similarities;
    vector<int> allUserIds = ratingManager.getAllUserIds();

    for (int uid : allUserIds) {
        if (uid == userId) continue;
        vector<Rating> otherRatings = ratingManager.findByUser(uid);
        int sim = SimilarityCalculate(myRatings, otherRatings);
        similarities.push_back({uid, sim});
    }

    sort(similarities.begin(), similarities.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second > b.second;
         });

    vector<int> result;
    int limit = min(k, (int)similarities.size());
    for (int i = 0; i < limit; i++) {
        result.push_back(similarities[i].first);
    }
    return result;
}

vector<int> Recommender::recommend(int userId, int n) const {
    vector<Rating> myRatings = ratingManager.findByUser(userId);

    if (myRatings.empty()) {
        return {};
    }

    set<int> myMovieIds;
    for (const auto& r : myRatings) {
        myMovieIds.insert(r.getMovieId());
    }

    vector<int> similarUsers = findSimilarUsers(userId, 5);

    if (similarUsers.empty()) {
        return {};
    }

    map<int, double> movieScores;
    for (int uid : similarUsers) {
        vector<Rating> otherRatings = ratingManager.findByUser(uid);
        for (const auto& r : otherRatings) {
            if (myMovieIds.find(r.getMovieId()) == myMovieIds.end()) {
                movieScores[r.getMovieId()] += r.getScore();
            }
        }
    }

    if (movieScores.empty()) {
        return {};
    }

    vector<pair<int, double>> sorted(movieScores.begin(), movieScores.end());
    sort(sorted.begin(), sorted.end(),
         [](const pair<int,double>& a, const pair<int,double>& b) {
             return a.second > b.second;
         });

    vector<int> result;
    int limit = min(n, (int)sorted.size());
    for (int i = 0; i < limit; i++) {
        result.push_back(sorted[i].first);
    }
    return result;
}
