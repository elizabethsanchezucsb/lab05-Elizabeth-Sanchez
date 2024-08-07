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

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    ifstream cardFile1(argv[1]);
    ifstream cardFile2(argv[2]);

    if (cardFile1.fail() || cardFile2.fail()) {
        cout << "Could not open file " << argv[1] << " or " << argv[2] << endl;
        return 1;
    }

    set<Card> aliceCards;
    set<Card> bobCards;

    loadCards(argv[1], aliceCards);
    loadCards(argv[2], bobCards);

    playGame(aliceCards, bobCards);

    return 0;
}
