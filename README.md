# Movie Recommender

C++로 구현한 영화 추천 시스템입니다.

## 기능
- 영화 추가 / 검색 / 평점순 정렬
- 사용자 추가 / 조회
- 평점 입력 / 조회
- 유사도 기반 영화 추천

## 빌드 및 실행

```bash
make run
```

## 프로젝트 구조

```
movie.recommender/
├── src/
│   ├── main.cpp
│   ├── Movie.h / Movie.cpp
│   ├── MovieManager.h / MovieManager.cpp
│   ├── User.h / User.cpp
│   ├── UserManager.h / UserManager.cpp
│   ├── Rating.h / Rating.cpp
│   ├── RatingManager.h / RatingManager.cpp
│   ├── BaseManager.h
│   ├── Recommender.h / Recommender.cpp
├── data/
│   ├── movies.csv
│   ├── users.csv
│   ├── ratings.csv
├── Makefile
└── README.md
```
