//cards.h
//Authors: Your Partner's Name and Your Name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

struct card{
    char number;
    char suit;
    card* next;
};


class Cards{

    private:
        card* top;

    public:
        Cards();
        ~Cards();
        void shuffleDeck();
        void addCard(char n, char s);
        friend void takeCardfromTop(Cards& source, Cards& target);
        friend void seekCard(Cards& source, Cards& target, char n, char s);
        friend ostream& operator <<(ostream& os, Cards& source);

};

#endif
