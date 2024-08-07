// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;
void loadCards(const string& filename, set<Card>& cards) {
    ifstream infile(filename);
    string suit;
    int value;
    while (infile >> suit >> value) {
        cards.insert(Card(suit, value));
    }
}

void printCards(const set<Card>& cards) {
    for (const auto& card : cards) {
        cout << card << endl;
    }
}

void playGame(set<Card>& aliceCards, set<Card>& bobCards) {
    // Game logic here
    auto aliceIt = aliceCards.begin();
    auto bobIt = bobCards.rbegin(); // reverse iterator for Bob's cards

    while (aliceIt != aliceCards.end() && bobIt != bobCards.rend()) {
        if (*aliceIt == *bobIt) {
            cout << "Alice picked matching card " << *aliceIt << endl;
            cout << "Bob picked matching card " << *bobIt << endl;
            aliceIt = aliceCards.erase(aliceIt);
            bobIt = set<Card>::reverse_iterator(bobCards.erase(next(bobIt).base()));
        } else if (*aliceIt < *bobIt) {
            ++aliceIt;
        } else {
            ++bobIt;
        }
    }

    cout << "Alice's cards:" << endl;
    printCards(aliceCards);
    cout << "Bob's cards:" << endl;
    printCards(bobCards);
}

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]); //basically ifstream == cin >> 
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){

  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){

  }
  cardFile2.close();
  
  
  return 0;
}
