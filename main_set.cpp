
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include "card.h"
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    CardList alice_cards;
    CardList bob_cards;

    // Read Alice's cards
    ifstream cardFile1(argv[1]);
    if (cardFile1.fail()) {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    string suit, value;
    string line;
    
    while (getline(cardFile1, line) && !line.empty()) {
        istringstream iss(line);
        if (iss >> suit >> value) {
            alice_cards.insert(Card(suit, value));
        }
    }
    cardFile1.close();

    // Read Bob's cards
    ifstream cardFile2(argv[2]);
    if (cardFile2.fail()) {
        cout << "Could not open file " << argv[2] << endl;
        return 1;
    }

    while (getline(cardFile2, line) && !line.empty()) {
        istringstream iss(line);
        if (iss >> suit >> value) {
            bob_cards.insert(Card(suit, value));
        }
    }
    cardFile2.close();

    // Game logic
    bool matchFound;
    bool aliceTurn = true;  // Flag to alternate turns
    bool anyMatchFound = false;

    do {
        matchFound = false;
        Card match("", "");

        if (aliceTurn) {
            // Alice's turn
            try {
                Card current = alice_cards.getMin();
                while (true) {
                    if (bob_cards.find(current)) {
                        cout << "Alice picked matching card " << current << endl;
                        bob_cards.remove(current);
                        alice_cards.remove(current);
                        matchFound = true;
                        anyMatchFound = true;
                        break;
                    }
                    current = alice_cards.getNext(current);
                }
            } catch (...) {}
        } else {
            // Bob's turn
            try {
                Card current = bob_cards.getMin();
                while (true) {
                    if (alice_cards.find(current)) {
                        cout << "Bob picked matching card " << current << endl;
                        alice_cards.remove(current);
                        bob_cards.remove(current);
                        matchFound = true;
                        anyMatchFound = true;
                        break;
                    }
                    current = bob_cards.getNext(current);
                }
            } catch (...) {}
        }

        // Switch turns only if a match was found
        if (matchFound) {
            aliceTurn = !aliceTurn;
        }
    } while (matchFound && !alice_cards.empty() && !bob_cards.empty());

    // Print final hands
    if (anyMatchFound) {
        cout << endl;
    }

    cout << "Alice's cards:" << endl;
    alice_cards.print();

    cout << endl << "Bob's cards:" << endl;
    bob_cards.print();

    return 0;
}