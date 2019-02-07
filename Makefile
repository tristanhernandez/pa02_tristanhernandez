game: cards.cpp main.cpp
	g++ -o game cards.cpp cards.h main.cpp

unittest: cards.cpp testcards.cpp
	g++ -o unittest cards.cpp testcards.cpp
