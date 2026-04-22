#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "movie.h"

class movie_manager {
private:
    std::vector<Movie> movies;

public:
    void add_movie_direct(const Movie& m) {
        movies.push_back(m);
    }

    void add_movie() {
        Movie temp;
        if (std::cin >> temp) {
            movies.push_back(temp);
        } else {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    void search_by_title() const {
        std::string title;
        std::cout << "검색어: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, title);
        for (const auto& m : movies) {
            if (m.getTitle().find(title) != std::string::npos) {
                std::cout << m << std::endl;
            }
        }
    }

    void print_all() const {
        for (const auto& m : movies) std::cout << m << std::endl;
    }

    void sort_and_print() {
        std::vector<Movie> sorted = movies;
        std::sort(sorted.begin(), sorted.end());
        for (const auto& m : sorted) std::cout << m << std::endl;
    }

    Movie* find_by_id(int id) {
        for (auto& m : movies) {
            if (m.getId() == id) return &m;
        }
        return nullptr;
    }
};