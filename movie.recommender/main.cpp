#include <iostream>
#include <vector>
#include "movie.h"
#include "user.h"
#include "rating.h"

using namespace std;

int main() {
    vector<Movie> movies;
    movies.push_back(Movie(1, "그것만이 내세상", "코미디", 2018)); 
    movies.push_back(Movie(2, "식스센스", "스릴러", 1999));

    User me(20252811, "방현민", "bhmin0217@gmail.com");

    Rating r1(me.getId(), movies[0].getId(), 5.0);
    movies[0].addRating(r1.getScore());

    Rating r2(me.getId(), movies[1].getId(), 9.9);
    movies[1].addRating(r2.getScore());

    cout << "========== [ 사용자 정보 ] ==========" << endl;
    me.display();

    cout << "\n========== [ 평점 기록 ] ==========" << endl;
    r1.display();
    r2.display();

    cout << "\n========== [ 영화 전체 목록 ] ==========" << endl;
    for (size_t i = 0; i < movies.size(); ++i) {
        movies[i].display();
    }

    return 0;
}