#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Movie {
private:
    int id;
    string title;
    int year;
    double rating;

public:
    Movie(int i, const string& t, int y, double r)
        : id(i), title(t), year(y), rating(r) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    int getYear() const { return year; }
    double getRating() const { return rating; }

    friend ostream& operator<<(ostream& os, const Movie& m) {
        os << "[" << m.id << "] " << m.title << " (" << m.year << ") ★ " << m.rating;
        return os;
    }
};

class MovieManager {
private:
    vector<Movie> movies;

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void printAll() const {
        for (const auto& m : movies) {
            cout << m << endl;
        }
        cout << "총 " << movies.size() << "편" << endl;
    }

    int getCount() const {
        return movies.size();
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: " << filename << " 파일을 열 수 없습니다." << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            getline(ss, token, ',');
            int id = stoi(token);

            getline(ss, token, ',');
            string title = token;

            getline(ss, token, ',');
            int year = stoi(token);

            getline(ss, token, ',');
            double rating = stod(token);

            addMovie(Movie(id, title, year, rating));
        }

        file.close();
        cout << filename << " 로드 완료: " << movies.size() << "건" << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: " << filename << " 저장 실패" << endl;
            return;
        }

        file << "id,title,year,rating" << endl;

        for (const auto& m : movies) {
            file << m.getId() << ","
                 << m.getTitle() << ","
                 << m.getYear() << ","
                 << m.getRating() << endl;
        }

        file.close();
        cout << filename << " 저장 완료: " << movies.size() << "건" << endl;
    }
};

int main() {
    MovieManager mgr;

    cout << "=== 프로그램 시작: CSV 로드 ===" << endl;
    mgr.loadFromFile("data/movies.csv");
    mgr.printAll();

    cout << "\n=== 영화 추가 ===" << endl;
    int nextId = mgr.getCount() + 1;
    mgr.addMovie(Movie(nextId, "Your Name", 2016, 8.4));
    cout << "추가 완료!" << endl;

    cout << "\n=== 현재 목록 ===" << endl;
    mgr.printAll();

    cout << "\n=== 프로그램 종료: CSV 저장 ===" << endl;
    mgr.saveToFile("data/movies.csv");

    cout << "\n=== 영속성 테스트: 새 Manager로 다시 로드 ===" << endl;
    MovieManager mgr2;
    mgr2.loadFromFile("data/movies.csv");
    mgr2.printAll();

    return 0;
}