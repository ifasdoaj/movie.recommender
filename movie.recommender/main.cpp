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
    User user2(20250001, "김철수", "chulsoo@example.com");
    User user3(20250002, "이영희", "younghee@example.com");

    Rating r1_1(me.getId(), movies[0].getId(), 5.0);
    Rating r1_2(user2.getId(), movies[0].getId(), 4.0);
    Rating r1_3(user3.getId(), movies[0].getId(), 4.5);
    
    movies[0].addRating(r1_1.getScore());
    movies[0].addRating(r1_2.getScore());
    movies[0].addRating(r1_3.getScore());

    Rating r2_1(me.getId(), movies[1].getId(), 5.0);
    Rating r2_2(user2.getId(), movies[1].getId(), 4.8);
    Rating r2_3(user3.getId(), movies[1].getId(), 9.9); 

    movies[1].addRating(r2_1.getScore());
    movies[1].addRating(r2_2.getScore());
    movies[1].addRating(r2_3.getScore());

    cout << "========== [ 등록된 사용자 목록 ] ==========" << endl;
    me.display();
    user2.display();
    user3.display();

    cout << "\n========== [ 상세 평점 기록 ] ==========" << endl;
    r1_1.display();
    r1_2.display();
    r1_3.display();
    r2_1.display();
    r2_2.display();

    cout << "\n========== [ 영화 목록 (평균 평점 반영) ] ==========" << endl;
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << movies[i] << endl; 
    }

    return 0;
}