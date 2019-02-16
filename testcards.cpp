// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

//using namespace std;

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
  //tests all methods added into cards.h
  //

  nextSuit = 'c';
  nextNum = '3';
  if ( seekCard(Alice.hand, Bob.hand, nextSuit, nextNum) ) {
      cout << Alice.getName() << " picked matching card "<<nextSuit<<" "<<nextNum<<endl;
  } else {
      cout << "no card "<<nextSuit<<" "<<nextNum<<" found"<<endl;
   }
    cout<<Alice<<endl<<Bob<<endl;


  nextSuit = 'c';
  nextNum = '3';
  if ( seekCard(Alice.hand, Bob.hand, nextSuit, nextNum) ) {
      cout << Alice.getName() << " picked matching card "<<nextSuit<<" "<<nextNum<<endl;
  } else {
      cout << "no card "<<nextSuit<<" "<<nextNum<<" found"<<endl;
   }
    cout<<Alice<<endl<<Bob<<endl;


  nextSuit = 'h'; //h 3 is in Alice but not Bob
  nextNum = '3';
  if ( seekCard(Alice.hand, Bob.hand, nextSuit, nextNum) ) {
      cout << Alice.getName() << " picked matching card "<<nextSuit<<" "<<nextNum<<endl;
  } else {
      cout << "no card "<<nextSuit<<" "<<nextNum<<" found"<<endl;
   }
    cout<<Alice<<endl<<Bob<<endl;


  //CardList copyConstrTest(Alice.hand);
  //cout<<copyConstrTest<<endl;
  //delete copyConstrTest;

    return 0;
}
