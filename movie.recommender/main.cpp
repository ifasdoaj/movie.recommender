#include <iostream>
#include "movie_manager.h"
#include "user_manager.h"

using namespace std;

int main() {
    movie_manager movie_mgr;
    user_manager user_mgr;

    movie_mgr.add_movie_direct(Movie(1, "그것만이 내세상", "코미디", 2018));
    movie_mgr.add_movie_direct(Movie(2, "식스센스", "스릴러", 1999));
    
    user_mgr.add_user_direct(User(20252811, "방현민", "bhmin0217@gmail.com"));
    user_mgr.add_user_direct(User(20250001, "김철수", "chulsoo@example.com"));
    user_mgr.add_user_direct(User(20250002, "이영희", "younghee@example.com"));

    Movie* m1 = movie_mgr.find_by_id(1);
    Movie* m2 = movie_mgr.find_by_id(2);
    
    if (m1) { 
        m1->addRating(5.0); 
        m1->addRating(4.0); 
        m1->addRating(4.5); 
    }
    if (m2) { 
        m2->addRating(5.0); 
        m2->addRating(4.8); 
        m2->addRating(0.0); 
    }

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
            case 1: movie_mgr.add_movie(); break;
            case 2: movie_mgr.search_by_title(); break;
            case 3: movie_mgr.print_all(); break;
            case 4: movie_mgr.sort_and_print(); break;
            case 5: user_mgr.add_user(); break;
            case 6: user_mgr.print_all(); break;
            case 7: {
                int m_id; double score;
                cout << "영화 ID: "; cin >> m_id;
                cout << "평점(0-5): "; cin >> score;
                Movie* m = movie_mgr.find_by_id(m_id);
                if (m) m->addRating(score);
                else cout << "해당 영화가 없습니다." << endl;
                break;
            }
            case 8: movie_mgr.print_all(); break;
        }
    }
    return 0;
}