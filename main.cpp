// Feb 14: This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

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
    bool foundMatch = true;
    while (foundMatch) {
        foundMatch = false;

        for (const auto& card : aliceCards) {
            if (bobCards.find(card) != bobCards.end()) {
                cout << "Alice picked matching card " << card << endl;
                aliceCards.erase(card);
                bobCards.erase(card);
                foundMatch = true;
                break;
            }
        }

        for (auto it = bobCards.rbegin(); it != bobCards.rend(); ++it) {
            if (aliceCards.find(*it) != aliceCards.end()) {
                cout << "Bob picked matching card " << *it << endl;
                bobCards.erase(*it);
                aliceCards.erase(*it);
                foundMatch = true;
                break;
            }
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
