CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = movie.recommender
SRCS = main.cpp movie.cpp user.cpp rating.cpp movie_manager.cpp user_manager.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)