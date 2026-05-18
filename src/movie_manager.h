#pragma once
#include <vector>
#include <string>
#include "movie.h"
#include "rating_manager.h"
#include "user_manager.h"

class MovieManager {
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
};
