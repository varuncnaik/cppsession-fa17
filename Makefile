CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

all: main

main: main.cpp Relation.o Tuple.o
	$(CC) $(CFLAGS) $^ -o $@

Tuple.o: Tuple.h

Relation.o: Tuple.h Relation.h Relation.cpp

clean:
	rm -rf *.o main
