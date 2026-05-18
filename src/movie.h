#pragma once
#include <string>
#include <iostream>

class Movie {
private:
    int id;
    std::string title;
    std::string genre;
    int releaseYear;
    double totalRating;
    int ratingCount;
    int addedByUserId;

public:
    Movie();
    Movie(int mId, std::string mTitle, std::string mGenre, int mYear, int userId = 0);

    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getReleaseYear() const;
    double getAverageRating() const;
    int getAddedByUserId() const;

    void addRating(double r);
    void resetRatingData();  // ← 추가됨

    friend std::ostream& operator<<(std::ostream& os, const Movie& m);
    friend std::istream& operator>>(std::istream& is, Movie& m);
    bool operator<(const Movie& other) const;
};
