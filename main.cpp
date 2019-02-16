#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  Player Alice("Alice");
  Player Bob("Bob");
  // to contain two sets of cards in two input files
  
  char nextNum = 'A';
  char nextSuit = 'A';

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
      nextSuit = line.at(0);
      nextNum = line.at(2);
      Alice.hand.addCard(nextSuit, nextNum);
  //    cout<<"TEST"<<Alice<<endl;
  }
  cardFile1.close();

  cout<<Alice<<endl;


  while (getline (cardFile2, line) && (line.length() > 0)){
      nextSuit = line.at(0);
      nextNum = line.at(2);
      Bob.hand.addCard(nextSuit, nextNum);
  //    cout<<"TEST"<<Bob<<endl;
  }
  cardFile2.close();

  cout<<Bob<<endl;

  //
  // Start the game
  //

  bool FirstPlayerTurn = true; //when this is true, it's Alice's turn
  
  card* tmp = Alice.hand.getHead();
  while( tmp )
  {
   //iterates through a player's cards until a match is found
   //Alternates player after every match.
   //Once there's no more matches, print both player's hands
   nextSuit = tmp->suit;
   nextNum  = tmp->number;

        if (FirstPlayerTurn)
        {
            if ( seekCard( Alice.hand, Bob.hand, nextSuit, nextNum) ){
                cout<< Alice.getName() <<" picked matching card "
                    <<nextSuit<<" "<<nextNum<<endl;
                FirstPlayerTurn = false;
                tmp = Bob.hand.getHead();
            }
            else
            {
                tmp = tmp->next;
            }
        }
        else
        {

            if ( seekCard( Bob.hand, Alice.hand, nextSuit, nextNum ) ){
                cout<< Bob.getName() <<" picked matching card "
                    <<nextSuit<<" "<<nextNum<<endl;
                FirstPlayerTurn = true;
                tmp = Alice.hand.getHead();
            }
            else
            {
                tmp = tmp->next;
            }
        }

  }

  cout << Alice << endl << Bob;

  return 0;
}
