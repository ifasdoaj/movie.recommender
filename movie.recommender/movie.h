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
    std::string getGenre() const;
    int getReleaseYear() const;
    double getAverageRating() const;

    void addRating(double r);

    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;
    bool operator<(const Movie& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Movie& m);
};