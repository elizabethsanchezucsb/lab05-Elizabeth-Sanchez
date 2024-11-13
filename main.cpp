// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include <sstream>

using namespace std;

void loadCards(const string& filename, CardList& cards) {
    ifstream cardFile(filename);
    string suit, value;
    string line;

    while (getline(cardFile, line) && !line.empty()) {
        istringstream iss(line);
        if (iss >> suit >> value) {
            cards.insert(Card(suit, value));
        }
    }
    cardFile.close();
}

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    CardList aliceHand, bobHand;
    loadCards(argv[1], aliceHand);
    loadCards(argv[2], bobHand);

    bool matchFound;
    bool aliceTurn = true;  // Flag to alternate turns
    do {
        matchFound = false;

        if (aliceTurn) {
            // Alice's turn
            vector<Card> aliceCards = aliceHand.getAllCards();
            for (const auto& card : aliceCards) {
                if (bobHand.find(card)) {
                    cout << "Alice picked matching card " << card << endl;
                    bobHand.remove(card);
                    aliceHand.remove(card);
                    matchFound = true;
                    break;
                }
            }
        } else {
            // Bob's turn
            vector<Card> bobCards = bobHand.getAllCards();
            // Process Bob's cards in reverse order
            for (auto it = bobCards.rbegin(); it != bobCards.rend(); ++it) {
                if (aliceHand.find(*it)) {
                    cout << "Bob picked matching card " << *it << endl;
                    aliceHand.remove(*it);
                    bobHand.remove(*it);
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
    cout << endl;
    cout << "Alice's cards:" << endl;
    aliceHand.print(cout);
    cout << endl;

    cout << "Bob's cards:" << endl;
    bobHand.print(cout);

    return 0;
}