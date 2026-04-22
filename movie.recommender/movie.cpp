#include "movie.h"
#include <iostream>

using namespace std;

Movie::Movie() : id(0), title(""), genre(""), releaseYear(0), totalRating(0.0), ratingCount(0) {}

Movie::Movie(int mId, string mTitle, string mGenre, int mYear) 
    : id(mId), title(mTitle), genre(mGenre), releaseYear(mYear), totalRating(0.0), ratingCount(0) {}

int Movie::getId() const { return id; }
string Movie::getTitle() const { return title; }
string Movie::getGenre() const { return genre; }
int Movie::getReleaseYear() const { return releaseYear; }

double Movie::getAverageRating() const {
    if (ratingCount == 0) return 0.0;
    return totalRating / ratingCount;
}

void Movie::addRating(double r) {
    if (r >= 0.0 && r <= 5.0) {
        totalRating += r;
        ratingCount++;
    }
}

void Movie::display() const {
    cout << "ID: " << id << " | " << title << " (" << releaseYear << ") [" << genre << "] "
         << "- 평균 평점: " << getAverageRating() << " (" << ratingCount << "명 참여)" << endl;
}

bool Movie::operator==(const Movie& other) const {
    return this->title == other.title;
}

bool Movie::operator<(const Movie& other) const {
    if (this->getAverageRating() != other.getAverageRating()) {
        return this->getAverageRating() > other.getAverageRating();
    }
    return this->title < other.title;
}