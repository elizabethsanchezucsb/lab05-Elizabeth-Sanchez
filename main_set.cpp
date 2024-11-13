// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include <sstream>
#include <vector>

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

void findAndProcessMatches(CardList& aliceHand, CardList& bobHand) {
    vector<Card> matches;
    vector<Card> aliceCards = aliceHand.getAllCards();

    // First, collect all matches in the order they appear in Alice's hand
    for (const auto& card : aliceCards) {
        if (bobHand.find(card)) {
            matches.push_back(card);
        }
    }

    // Process matches in the order they appear
    for (size_t i = 0; i < matches.size(); i++) {
        if (i % 2 == 0) {
            // Alice's turn
            cout << "Alice picked matching card " << matches[i] << endl;
        } else {
            // Bob's turn
            cout << "Bob picked matching card " << matches[i] << endl;
        }
        aliceHand.remove(matches[i]);
        bobHand.remove(matches[i]);
    }

    if (!matches.empty()) {
        cout << endl;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    CardList aliceHand, bobHand;
    loadCards(argv[1], aliceHand);
    loadCards(argv[2], bobHand);

    findAndProcessMatches(aliceHand, bobHand);

    cout << "Alice's cards:" << endl;
    aliceHand.print(cout);
    cout << endl;

    cout << "Bob's cards:" << endl;
    bobHand.print(cout);

    return 0;
}