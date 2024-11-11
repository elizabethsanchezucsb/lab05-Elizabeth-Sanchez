
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include "card.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " alice_cards.txt bob_cards.txt" << endl;
        return 1;
    }

    CardList alice_cards;
    CardList bob_cards;

    // Read Alice's cards
    string alice_filename(argv[1]);
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
    string bob_filename(argv[2]);
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
    bool game_continues = true;

    while (game_continues && !alice_cards.empty() && !bob_cards.empty()) {
        game_continues = false;
        
        if (alice_turn) {
            try {
                Card current = alice_cards.getMin();
                while (true) {
                    if (bob_cards.find(current)) {
                        cout << "Alice picked matching card " << current << endl;
                        alice_cards.remove(current);
                        bob_cards.remove(current);
                        game_continues = true;
                        break;
                    }
                    current = alice_cards.getNext(current);
                }
            } catch (...) {}
        } else {
            try {
                Card current = bob_cards.getMin();
                while (true) {
                    if (alice_cards.find(current)) {
                        cout << "Bob picked matching card " << current << endl;
                        bob_cards.remove(current);
                        alice_cards.remove(current);
                        game_continues = true;
                        break;
                    }
                    current = bob_cards.getNext(current);
                }
            } catch (...) {}
        }
        
        if (game_continues) {
            alice_turn = !alice_turn;
        }
    }

    if (!alice_cards.empty() || !bob_cards.empty()) {
        cout << endl;
    }

    cout << "Alice's cards:" << endl;
    alice_cards.print();

    cout << endl << "Bob's cards:" << endl;
    bob_cards.print();

    return 0;
}