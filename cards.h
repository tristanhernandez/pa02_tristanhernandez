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


class CardList{

    private:
        card* head;
        card* tail;

    public:
        CardList();
        ~CardList();
        //CardList(const CardList& source);
        //CardList& operator = (const Cardlist& source)
        card* getHead() const;
        void addCard(char n, char s);
        void deleteAll();
        friend bool seekCard(CardList& c1, CardList& c2, char n, char s);
        bool seekCard2(char n, char s);
        friend ostream& operator <<(ostream& os, const CardList& source);

};


class Player{

    private:
        string name;
    public:
        CardList hand;
        Player(string n);
        string getName() const;
        friend ostream& operator <<(ostream& os, const Player& source);
};


ostream& operator <<(ostream& os, const card* source);

#endif
