# Makefile
CXX_FLAG = --std=c++11 -g

all: game unittest

game: cards.o main.o
	g++ $(CXX_FLAG) -o game cards.o main.o

unittest: cards.o testcards.o
	g++ $(CXX_FLAG) -o unittest cards.o testcards.o

game.o: game.cpp
	g++ -c $(CXX_FLAG) game.cpp

unittest.o: unittest.cpp
	g++ -c $(CXX_FLAG) unittest.cpp
	
clean:
	rm -f testrest testlist *.o
