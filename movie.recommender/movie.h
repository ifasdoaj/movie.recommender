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

public:
    Movie();
    Movie(int mId, std::string mTitle, std::string mGenre, int mYear);

    int getId() const;
    std::string getTitle() const;
    double getAverageRating() const;

    void addRating(double r);

    friend std::ostream& operator<<(std::ostream& os, const Movie& m);
    friend std::istream& operator>>(std::istream& is, Movie& m);
    bool operator<(const Movie& other) const;
};