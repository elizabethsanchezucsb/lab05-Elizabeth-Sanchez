// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include "card.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " alice_cards.txt bob_cards.txt" << endl;
        return 1;
    }

    // Create card lists for both players
    CardList alice_cards;
    CardList bob_cards;

    // Read Alice's cards
    ifstream alice_file(argv[1]);
    if (!alice_file.is_open()) {
        cout << "Could not open " << argv[1] << endl;
        return 1;
    }

    string suit, value;
    while (alice_file >> suit >> value) {
        alice_cards.insert(Card(suit, value));
    }
    alice_file.close();

    // Read Bob's cards
    ifstream bob_file(argv[2]);
    if (!bob_file.is_open()) {
        cout << "Could not open " << argv[2] << endl;
        return 1;
    }

    while (bob_file >> suit >> value) {
        bob_cards.insert(Card(suit, value));
    }
    bob_file.close();

    // Game logic
    bool alice_turn = true;
    while (true) {
        bool found_match = false;

        if (alice_turn) {
            // Alice's turn - she looks through her cards from lowest to highest
            if (!alice_cards.empty()) {
                try {
                    Card current = alice_cards.getMin();
                    while (true) {
                        if (bob_cards.find(current)) {
                            cout << "Alice picked matching card " << current << endl;
                            bob_cards.remove(current);
                            alice_cards.remove(current);
                            found_match = true;
                            break;
                        }
                        try {
                            current = alice_cards.getNext(current);
                        } catch (const runtime_error&) {
                            break;  // No more cards to check
                        }
                    }
                } catch (const runtime_error&) {
                    // Handle empty list
                }
            }
        } else {
            // Bob's turn - he looks through his cards from lowest to highest
            if (!bob_cards.empty()) {
                try {
                    Card current = bob_cards.getMin();
                    while (true) {
                        if (alice_cards.find(current)) {
                            cout << "Bob picked matching card " << current << endl;
                            alice_cards.remove(current);
                            bob_cards.remove(current);
                            found_match = true;
                            break;
                        }
                        try {
                            current = bob_cards.getNext(current);
                        } catch (const runtime_error&) {
                            break;  // No more cards to check
                        }
                    }
                } catch (const runtime_error&) {
                    // Handle empty list
                }
            }
        }

        // If no match was found, game is over
        if (!found_match) {
            break;
        }

        // Switch turns
        alice_turn = !alice_turn;
    }

    // Print remaining cards
    cout << "\nAlice's cards:" << endl;
    alice_cards.print();

    cout << "\nBob's cards:" << endl;
    bob_cards.print();

    return 0;
}