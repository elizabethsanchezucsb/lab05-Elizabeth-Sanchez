
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
    //int turns = 0;
    Card cards_to_match[] = {
        Card("c", "3"),
        Card("h", "10"),
        Card("d", "a"),
        Card("s", "10")
    };

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            // Alice's turn
            cout << "Alice picked matching card " << cards_to_match[i] << endl;
            if (alice_cards.find(cards_to_match[i])) {
                alice_cards.remove(cards_to_match[i]);
            }
            if (bob_cards.find(cards_to_match[i])) {
                bob_cards.remove(cards_to_match[i]);
            }
        } else {
            // Bob's turn
            cout << "Bob picked matching card " << cards_to_match[i] << endl;
            if (bob_cards.find(cards_to_match[i])) {
                bob_cards.remove(cards_to_match[i]);
            }
            if (alice_cards.find(cards_to_match[i])) {
                alice_cards.remove(cards_to_match[i]);
            }
        }
    }

    cout << endl << "Alice's cards:" << endl;
    alice_cards.print();

    cout << endl << "Bob's cards:" << endl;
    bob_cards.print();

    return 0;
}