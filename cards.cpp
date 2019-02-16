//cards.cpp
//Authors: Tristan Hernandez
//Implementation of the classes defined in cards.h

#include "cards.h"
using namespace std;

//
//FUNCTIONS FOR CARDLIST
//

CardList::CardList() {
    head = NULL;
    tail = NULL;
}

CardList::~CardList(){
    //Destructor: deletes all cards linked to top
    //as well as the Cards object
    deleteAll();
}

/*

//Copy constr. and assign. operator were unneeded in the lab

CardList::CardList(CardList& source){
    //Copy Constructor
    card* tmp = source.head;
    card* newTmp = new card;
    this->head = newTmp;
        while (tmp){
            newTmp->suit   = tmp->suit;
            newTmp->number = tmp->number;
            tmp = tmp->next;
                if(tmp){
                    newTmp->next = new card;
                    newTmp = newTmp->next;
                }
                else
                    tail = newTmp;
                    newTmp->next = NULL;
        }
}
*/

card* CardList::getHead() const{
    //returns the head of the list
    return head;
}

void CardList::addCard(char s, char n){
    //adds a new card at the end of the list
    card* newCard = new card;
    newCard->number = n;
    newCard->suit = s;
    newCard->next = NULL;
    if (head == NULL){
        head = newCard;
        tail = newCard;
        return;
    }
    tail->next = newCard;
    tail = newCard;
}

bool seekCard(CardList& c1, CardList& c2, char s, char n){
    //Checks two CardLists if they both have the
    //card indicated by Number n and Suit s
    //If both have the card indicated, it deletes the first
    //instance of the card indicated in both CardLists
    card* tmp = c1.head;
    card* tmpPrev = NULL;
        if (tmp->number == n && tmp->suit == s){

            if( c2.seekCard2( s, n ) ){
                c1.head = c1.head->next;
                delete tmp;
                return true;
            } else {
                return false;
            }

        }
    tmpPrev = tmp;
    tmp = tmp->next;
    while (tmp){
        if (tmp->number == n && tmp->suit == s){
            
            if ( c2.seekCard2( s, n ) ) {
                tmpPrev->next = tmp->next;
                delete tmp;
                return true;
            } else {
                return false;
            }

        }
        tmpPrev = tmp;
        tmp = tmp->next;
    }
    return false;
}

bool CardList::seekCard2(char s, char n){
    //continuation of seekCard1, called if the card
    //in seekCard1 was found in hand1
    card* tmp = head;
    card* tmpPrev = NULL;

        if (tmp->number == n && tmp->suit == s){
            head = head->next;
            delete tmp;
            return true;
        }

    tmpPrev = tmp;
    tmp = tmp->next;
    while (tmp){

        if (tmp->number == n && tmp->suit == s){
            tmpPrev->next = tmp->next;
            delete tmp;
            return true;
        }

        tmpPrev = tmp;
        tmp = tmp->next;
    }
    return false;
}

void CardList::deleteAll(){
    //deletes all cards
    if( head != NULL )
    {
        card* tmp = head;
        card* del = head;
        while (tmp) {
        
            tmp = tmp->next;
            delete del;
            del = tmp;
        }
        head = NULL;
        tail = NULL;
    }
}

ostream& operator <<(ostream& os, const CardList& source){
    //prints all cards in the list
    card* tmp = source.head;
    while (tmp){
        os << tmp;
        tmp = tmp->next;
    }
    return os;
}

//
//  FUNCTIONS FOR PLAYER
//

Player::Player(string n){
    //initializes a player with a name
    //Their hand always starts empty
    name = n;
}

string Player::getName() const{
    //returns the name
    return name;
}

ostream& operator <<(ostream& os, const Player& source){
    //prints the player's hand
    os << source.name << "'s cards:" << endl << source.hand;
    return os;
}

//
//  NON-MEMBER FUNCTIONS
//

ostream& operator <<(ostream& os, const card* source){
    os << source->suit << " " << source->number << endl;
    return os;
}
