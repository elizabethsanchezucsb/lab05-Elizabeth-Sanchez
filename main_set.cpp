// main_set.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
    if(argv < 3){
        cout << "Please provide 2 file names" << endl;
        return 1;
    }
  
    ifstream cardFile1(argc[1]);
    ifstream cardFile2(argc[2]);
    string line;

    if (cardFile1.fail() || cardFile2.fail()){
        cout << "Could not open file " << argc[2];
        return 1;
    }

    set<Card> aliceCards;
    set<Card> bobCards;

    // Read each file
    while (getline(cardFile1, line) && (line.length() > 0)){
        char suit = line[0];
        string rank = line.substr(2);
        aliceCards.insert(Card(suit, rank));
    }
    cardFile1.close();

    while (getline(cardFile2, line) && (line.length() > 0)){
        char suit = line[0];
        string rank = line.substr(2);
        bobCards.insert(Card(suit, rank));
    }
    cardFile2.close();

    // Game logic
    // Implement logic to compare cards between aliceCards and bobCards

    return 0;
}