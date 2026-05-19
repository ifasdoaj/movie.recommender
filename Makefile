CC = g++
CFLAGS = -Wall -g
TARGET = movie.recommender

SRCS = src/main.cpp src/movie.cpp src/user.cpp src/rating.cpp \
       src/movie_manager.cpp src/user_manager.cpp src/rating_manager.cpp \
       src/Recommender.cpp src/SimilarityCalculator.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
