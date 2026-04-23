#include "movie.h"
#include <iomanip>

using namespace std;

Movie::Movie() : id(0), title(""), genre(""), releaseYear(0), totalRating(0.0), ratingCount(0) {}

Movie::Movie(int mId, string mTitle, string mGenre, int mYear) 
    : id(mId), title(mTitle), genre(mGenre), releaseYear(mYear), totalRating(0.0), ratingCount(0) {}

int Movie::getId() const { return id; }
string Movie::getTitle() const { return title; }

double Movie::getAverageRating() const {
    return (ratingCount == 0) ? 0.0 : totalRating / ratingCount;
}

void Movie::addRating(double r) {
    if (r >= 0.0 && r <= 5.0) {
        totalRating += r;
        ratingCount++;
    }
}

ostream& operator<<(ostream& os, const Movie& m) {
    os << "ID: " << m.id << " | " << setw(20) << left << m.title 
       << " | " << m.releaseYear << " | " << m.genre 
       << " | 평점: " << fixed << setprecision(1) << m.getAverageRating()
       << " (" << m.ratingCount << "명)";
    return os;
}

istream& operator>>(istream& is, Movie& m) {
    cout << "ID: "; is >> m.id;
    is.ignore(1000, '\n');
    cout << "제목: "; getline(is, m.title);
    cout << "장르: "; getline(is, m.genre);
    cout << "연도: "; is >> m.releaseYear;
    return is;
}

bool Movie::operator<(const Movie& other) const {
    return this->getAverageRating() > other.getAverageRating();
}