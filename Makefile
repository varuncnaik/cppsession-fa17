CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: main

main: main.cpp Relation.o Tuple.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Tuple.o: Tuple.h

Relation.o: Tuple.h Relation.h

clean:
	rm -rf *.o main
