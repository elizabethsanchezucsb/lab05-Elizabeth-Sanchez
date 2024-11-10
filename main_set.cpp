// Feb 14: This file should implement the game using the std::set container class
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include <sstream>
#include <algorithm>


using namespace std;
int main(int argc, char** argv) {  // Changed from char* argv[]
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " alice_cards.txt bob_cards.txt" << endl;
        return 1;
    }

    CardList alice_cards;
    CardList bob_cards;

    // Read Alice's cards
    string alice_filename(argv[1]);  // Convert char* to string
    ifstream alice_file(alice_filename);
    if (!alice_file.is_open()) {
        cout << "Could not open " << alice_filename << endl;
        return 1;
    }

    string suit, value;
    while (alice_file >> suit >> value) {
        alice_cards.insert(Card(suit, value));
    }
    alice_file.close();

    // Read Bob's cards
    string bob_filename(argv[2]);  // Convert char* to string
    ifstream bob_file(bob_filename);
    if (!bob_file.is_open()) {
        cout << "Could not open " << bob_filename << endl;
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
            CardNode* current = alice_cards.findMin();
            while (current) {
                if (bob_cards.find(current->card)) {
                    cout << "Alice picked matching card " << current->card << endl;
                    bob_cards.remove(current->card);
                    alice_cards.remove(current->card);
                    found_match = true;
                    break;
                }
                current = alice_cards.findNext(current);
            }
        } else {
            CardNode* current = bob_cards.findMin();
            while (current) {
                if (alice_cards.find(current->card)) {
                    cout << "Bob picked matching card " << current->card << endl;
                    alice_cards.remove(current->card);
                    bob_cards.remove(current->card);
                    found_match = true;
                    break;
                }
                current = bob_cards.findNext(current);
            }
        }

        if (!found_match) break;
        alice_turn = !alice_turn;
    }

    cout << "\nAlice's cards:" << endl;
    alice_cards.print();

    cout << "\nBob's cards:" << endl;
    bob_cards.print();

    return 0;
}