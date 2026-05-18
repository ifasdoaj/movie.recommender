#include <iostream>
#include "movie_manager.h"
#include "user_manager.h"
#include "rating_manager.h"

using namespace std;

int main() {
    RatingManager rating_mgr;
    UserManager user_mgr;
    MovieManager movie_mgr(rating_mgr, user_mgr);

    movie_mgr.addMovie(Movie(1, "그것만이 내세상", "코미디", 2018, 20252811));
    movie_mgr.addMovie(Movie(2, "식스센스", "스릴러", 1999, 20250001));

    user_mgr.addUser(User(20252811, "방현민", "bhmin0217@gmail.com"));
    user_mgr.addUser(User(20250001, "김철수", "chulsoo@example.com"));
    user_mgr.addUser(User(20250002, "이영희", "younghee@example.com"));

    movie_mgr.addRatingToMovie(1, 20252811, 5.0);
    movie_mgr.addRatingToMovie(1, 20250001, 4.0);
    movie_mgr.addRatingToMovie(1, 20250002, 4.5);
    movie_mgr.addRatingToMovie(2, 20252811, 5.0);
    movie_mgr.addRatingToMovie(2, 20250001, 4.8);
    movie_mgr.addRatingToMovie(2, 20250002, 0.0);

    int choice;
    while (true) {
        cout << "\n=== Movie Recommender ===\n" << endl;
        cout << "[ 영화 ]\n 1. 영화 추가\n 2. 제목으로 검색\n 3. 전체 목록 출력\n 4. 평점순 정렬 출력" << endl;
        cout << "\n[ 사용자 ]\n 5. 사용자 추가\n 6. 사용자 목록 출력" << endl;
        cout << "\n[ 평점 ]\n 7. 평점 입력\n 8. 영화별 평점 보기\n\n0. 종료\n\n선택 > ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                int userId;
                cout << "사용자 ID: "; cin >> userId;
                movie_mgr.addMovieByUser(userId);
                break;
            }
            case 2: {
                string title;
                cout << "검색할 제목: ";
                cin.ignore();
                getline(cin, title);
                movie_mgr.findByTitle(title);
                break;
            }
            case 3: movie_mgr.printAll(); break;
            case 4: movie_mgr.sortByRating(); break;
            case 5: {
                int id;
                string name, email;
                cout << "ID: "; cin >> id;
                cout << "이름: "; cin >> name;
                cout << "이메일: "; cin >> email;
                user_mgr.addUser(User(id, name, email));
                break;
            }
            case 6: user_mgr.printAll(); break;
            case 7: {
                int m_id, u_id;
                double score;
                cout << "영화 ID: "; cin >> m_id;
                cout << "사용자 ID: "; cin >> u_id;
                cout << "평점(0-5): "; cin >> score;
                movie_mgr.addRatingToMovie(m_id, u_id, score);
                break;
            }
            case 8: {
                int m_id;
                cout << "영화 ID: "; cin >> m_id;
                movie_mgr.printRatingsByMovieId(m_id);
                break;
            }
        }
    }
    return 0;
}
