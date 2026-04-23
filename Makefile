CC = g++
CFLAGS = -Wall -g
TARGET = movie_recommender

OBJS = main.o movie.o user.o rating.o movie_manager.o user_manager.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)