# Movie Recommender

20252811 방현민

## 프로젝트 구조

```
movie.recommender/
├── src/
│   ├── main.cpp
│   ├── movie.h / movie.cpp
│   ├── movie_manager.h / movie_manager.cpp
│   ├── user.h / user.cpp
│   ├── user_manager.h / user_manager.cpp
│   ├── rating.h / rating.cpp
│   ├── rating_manager.h / rating_manager.cpp
│   ├── BaseManager.h
│   ├── Recommender.h / Recommender.cpp
│   ├── SimilarityCalculator.h / SimilarityCalculator.cpp
├── data/
│   ├── movies.csv
│   ├── users.csv
│   ├── ratings.csv
│   ├── statistics.csv
├── Makefile
└── README.md
```

## 빌드 및 실행

```bash
make run
```
