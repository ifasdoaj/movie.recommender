#include <iostream>
#include "movie_manager.h"
#include "user_manager.h"
#include "rating_manager.h"
#include "Recommender.h"

using namespace std;

int main() {
    RatingManager rating_mgr;
    UserManager user_mgr;
    MovieManager movie_mgr(rating_mgr, user_mgr);
    Recommender recommender(movie_mgr, rating_mgr);

    user_mgr.loadFromFile("data/users.csv");
    rating_mgr.loadFromFile("data/ratings.csv");
    movie_mgr.loadFromFile("data/movies.csv");
    movie_mgr.syncRatings();

    int choice;
    while (true) {
        cout << "\n=== Movie Recommender ===\n" << endl;
        cout << "[ 영화 ]\n 1. 영화 추가\n 2. 제목으로 검색\n 3. 전체 목록 출력\n 4. 평점순 정렬 출력" << endl;
        cout << "\n[ 사용자 ]\n 5. 사용자 추가\n 6. 사용자 목록 출력" << endl;
        cout << "\n[ 평점 ]\n 7. 평점 입력\n 8. 영화별 평점 보기" << endl;
        cout << "\n[ 추천 ]\n 9. 영화 추천받기\n\n0. 종료\n\n선택 > ";

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
                cin.ignore(1000, '\n');
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
            case 9: {
                int u_id, n;
                cout << "사용자 ID: "; cin >> u_id;
                cout << "추천 영화 수: "; cin >> n;
                vector<int> result = recommender.recommend(u_id, n);
                if (result.empty()) {
                    cout << "추천할 영화가 없습니다." << endl;
                } else {
                    cout << "\n=== 추천 영화 ===" << endl;
                    for (int movieId : result) {
                        Movie* m = movie_mgr.findById(movieId);
                        if (m) cout << *m << endl;
                    }
                }
                break;
            }
        }
    }

    user_mgr.saveToFile("data/users.csv");
    rating_mgr.saveToFile("data/ratings.csv");
    movie_mgr.saveToFile("data/movies.csv");

    return 0;
}
