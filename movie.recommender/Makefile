CC = g++
CFLAGS = -Wall -g
TARGET = movie_recommender
OBJS = main.o movie.o user.o rating.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp movie_manager.h user_manager.h
	$(CC) $(CFLAGS) -c main.cpp

movie.o: movie.cpp movie.h
	$(CC) $(CFLAGS) -c movie.cpp

user.o: user.cpp user.h
	$(CC) $(CFLAGS) -c user.cpp

rating.o: rating.cpp rating.h
	$(CC) $(CFLAGS) -c rating.cpp

clean:
	rm -f $(OBJS) $(TARGET)