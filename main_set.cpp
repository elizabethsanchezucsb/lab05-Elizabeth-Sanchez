// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include <sstream>


using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  set<Card> aliceHand, bobHand;
  string suit;
  int value;
  

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    istringstream iss(line);
    if(iss >> suit >> value){
      aliceHand.insert(Card(suit, value));
    }
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    istringstream iss(line);
    if(iss >> suit >> value){
      bobHand.insert(Card(suit, value));
    }
  }
  cardFile2.close();
  

  //game LOGIC

  bool matchFound;
  do{
    matchFound = false;
  


    //alices turn = iterate forward
    for(auto it = aliceHand.begin(); it != aliceHand.end();){
      if(bobHand.find(*it) != bobHand.end()){
        cout << "Alice picked matching card " << it->suit << " " << it->value << endl;
        bobHand.erase(*it);
        it = aliceHand.erase(it);
        matchFound = true;
        break;
      }
      else{
        ++it;
      }
    }
//bobs turn iterating backwards
if(!matchFound){
    for( auto it = bobHand.rbegin(); it!= bobHand.rend();){
      if(aliceHand.find(*it) != aliceHand.end()){
        cout << "Bob picked matching card " << it->suit << " " << it->value << endl;
        aliceHand.erase(*it);
        it = decltype(it){bobHand.erase(next(it).base())};  // Corrected to handle reverse iterator

        matchFound = true;
        break; //bob only picks one card per turn
      }
      else{
        ++it;
      }
    }
}
  } while(matchFound);
    
    //print final cards
    cout << "\nAlice's cards: ";
    for(const auto& card : aliceHand){
      cout << card.suit <<  " " << card.value << endl;
    }
     cout << "\nBob's cards: ";
    for(const auto& card : bobHand){
      cout <<card.suit << " " << card.value << endl;
    }
 
    return 0;
      }
    


//this implies that
//- use std::set to store cards for each player
//set will keep cards in order and prevent duplicates
//create card class in card.h that represents a single card
//class should overload the less-than operator (<) to allow proper sorting in the set
//implement a function to parse each line from the input files and create Card objects 
//use set.insert() to add cards to each player's set.
//implement game logic using set operations. for example: 
//***use set_interection() to find common cards between players
//***use set_difference() to remove cards from a players set.
//***use set.size() to check number of cards each player has.
//std::set is implemented as a balanced binary search tree, (often a red-black tree) means you dont need to implement your own BST. The set will handle the bst operations internally
