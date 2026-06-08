#pragma once
#include <vector>
#include <string>
#include <map>
#include "movie.h"
#include "rating_manager.h"
#include "user_manager.h"
#include "BaseManager.h"

class MovieManager : public BaseManager {
private:
    std::vector<Movie> movies;
    RatingManager& ratingManager;
    UserManager& userManager;

public:
    MovieManager(RatingManager& rm, UserManager& um);

    void addMovie(const Movie& m);
    void addMovieByUser(int userId);
    void findByTitle(const std::string& title) const;
    void sortByRating();
    void printAll() const;
    void addRatingToMovie(int mId, int uId, double score);
    void printRatingsByMovieId(int mId) const;
    Movie* findById(int id);
    void syncRatings();

    double getAverageRating() const;
    std::map<std::string, double> getAverageRatingByGenre() const;
    std::vector<Movie> getTopN(int n) const;
    void exportStatisticsToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) const override;
    int size() const override { return movies.size(); }
};
