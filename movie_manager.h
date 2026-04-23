#pragma once
#include <vector>
#include <string>
#include "movie.h"

class movie_manager {
private:
    std::vector<Movie> movies;

public:
    void add_movie_direct(const Movie& m);
    void add_movie();
    void search_by_title() const;
    void print_all() const;
    void sort_and_print();
    Movie* find_by_id(int id);
};