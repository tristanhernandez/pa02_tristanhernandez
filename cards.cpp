//cards.cpp
//Authors: Your Partner's Name and Your Name
//Implementation of the classes defined in cards.h

#include "cards.h"
using namespace std;

Cards::Cards() {
    top = NULL;
}

Cards::~Cards(){
    card* tmp = top;
    card* del = top;
    while (tmp) {
        tmp = tmp->next;
        delete del;
        del = tmp;
    }
    top = NULL;
}
    
void Cards::shuffleDeck(){
    cout<<"no output";
}

void Cards::addCard(char n, char s){
    card* tmp = top;
    if (tmp ==  NULL){
        tmp = new card;
        tmp->number = n;
        tmp->suit = s;
        top = tmp;
        tmp->next = NULL;
        return;
    }
    while(tmp){
        if (tmp->next == NULL){
            card* last = new card;
            last->number = n;
            last->suit = s;
            tmp->next = last;
            last->next = NULL;
        }
    }
}
 
void takeCardfromTop(Cards& source, Cards& target){
    if (source.top) { //if there's a card on the Source object, it
                  //moves the first card to the first card of
                  //the target object
        card* tmp = source.top;
        source.top = source.top->next;
        tmp->next = target.top;
        target.top = tmp;
    }
}

void seekCard(Cards& source, Cards& target, char n, char s){
    card* tmp = target.top;
    card* tmpPrev = NULL;
        if (tmp->number == n && tmp->suit == s){
            target.top = target.top->next;
            tmp->next = source.top;
            source.top = tmp;
            return;
        }
    tmpPrev = tmp;
    tmp = tmp->next;
    while (tmp){
        if (tmp->number == n && tmp->suit == s){
            tmpPrev->next = tmp->next;
            tmp->next  = source.top;
            source.top = tmp;
            return;
        }
        tmpPrev = tmp;
        tmp = tmp->next;
    }
}

ostream& operator <<(ostream& os, Cards& source){
    card* tmp = source.top;
    while (tmp){
        os << tmp->suit <<" "<< tmp->number<<endl;
        tmp = tmp->next;
    }
    return os;
}
