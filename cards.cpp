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
    
void Cards::ShuffleDeck(){
    cout<<"no output";
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
    os << source.top->suit <<" "<< source.top->number;
    return os;
}
