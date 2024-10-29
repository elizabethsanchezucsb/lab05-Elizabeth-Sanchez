// Feb 14: This file should implement the game using the std::set container class
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include <sstream>
#include <algorithm>


using namespace std;

int main(int argc, char** argv){
    if(argc < 3){
        cout << "Please provide 2 file names" << endl;
        return 1;
    }
  
    ifstream cardFile1(argv[1]);
    ifstream cardFile2(argv[2]);

    if (cardFile1.fail() || cardFile2.fail()){
        cout << "Could not open file " << argv[2];
        return 1;
    }

    set<Card> aliceHand, bobHand;
    string suit, value;
    string line;

    // Read Alice's cards
    while (getline(cardFile1, line) && !line.empty()){
        istringstream iss(line);
        if(iss >> suit >> value){
            aliceHand.insert(Card(suit, value));
        }
    }
    cardFile1.close();

    // Read Bob's cards
    while (getline(cardFile2, line) && !line.empty()){
        istringstream iss(line);
        if(iss >> suit >> value){
            bobHand.insert(Card(suit, value));
        }
    }
    cardFile2.close();

    // Game logic
    bool matchFound;
    bool aliceTurn = true;  // Flag to alternate turns
    do {
        matchFound = false;

        if (aliceTurn) {
            // Alice's turn
            for (auto it = aliceHand.begin(); it != aliceHand.end(); ++it) {
                if (bobHand.find(*it) != bobHand.end()) {
                    cout << "Alice picked matching card " << *it << endl;
                    bobHand.erase(*it);
                    aliceHand.erase(it);
                    matchFound = true;
                    break;
                }
            }
        } else {
            // Bob's turn
            for (auto it = bobHand.rbegin(); it != bobHand.rend(); ++it) {
                if (aliceHand.find(*it) != aliceHand.end()) {
                    cout << "Bob picked matching card " << *it << endl;
                    aliceHand.erase(*it);
                    bobHand.erase(--it.base());
                    matchFound = true;
                    break;
                }
            }
        }

        // Switch turns only if a match was found
        if (matchFound) {
            aliceTurn = !aliceTurn;
        }
    } while (matchFound);

    // Print final hands
    cout << "\
Alice's cards:" << endl;
    for (const auto& card : aliceHand) {
        cout << card << endl;
    }
    cout << "\
Bob's cards:" << endl;
    for (const auto& card : bobHand) {
        cout << card << endl;
    }

    return 0;
}