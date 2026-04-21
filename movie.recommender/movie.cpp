#include "movie.h"

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

bool Movie::operator==(const Movie& other) const {
    return this->title == other.title; 
}

bool Movie::operator!=(const Movie& other) const {
    return !(*this == other);
}

bool Movie::operator<(const Movie& other) const {
    double thisAvg = this->getAverageRating();
    double otherAvg = other.getAverageRating();
    
    if (thisAvg != otherAvg) {
        return thisAvg < otherAvg;
    }
    return this->title < other.title;
}

ostream& operator<<(ostream& os, const Movie& m) {
    os << "ID: " << m.id << " | " << m.title << " (" << m.releaseYear << ") [" << m.genre << "] "
       << "- 평균 평점: " << m.getAverageRating() << " (" << m.ratingCount << "명 참여)";
    return os;
}