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
        //void deleteCard(char n, char s);
        void deleteAll();
        friend bool seekCard(CardList& c1, CardList& c2, char n, char s);
        bool seekCard2(char n, char s);
        //card* getNthCard(int num, card* nthCard );
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
//isSuit(char s){
//    //Checks if s is a valid char for a suit
//    if( s=='c' || s=='d' || s=='h' || s=='s' )
//        return true;
//    return false;

//isNum(char n){
//    Checks if n is a valid char for a number
//    if( n=='2' || n=='3' || n=='4' || n=='5'
//     || n=='6' || n=='7' || n=='8' || n=='9'
//     || n=='0' || n=='j' || n=='q' || n=='k'
//     || n=='a' )
//        return true;
//    return false;
//}

#endif
