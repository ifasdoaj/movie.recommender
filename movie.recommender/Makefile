CXX = g++
CXXFLAGS = -Wall -std=c++14

TARGET = main
OBJS = main.o movie.o user.o rating.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp movie.h user.h rating.h
	$(CXX) $(CXXFLAGS) -c main.cpp

movie.o: movie.cpp movie.h
	$(CXX) $(CXXFLAGS) -c movie.cpp

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp

rating.o: rating.cpp rating.h
	$(CXX) $(CXXFLAGS) -c rating.cpp

clean:
	rm -f $(OBJS) $(TARGET)