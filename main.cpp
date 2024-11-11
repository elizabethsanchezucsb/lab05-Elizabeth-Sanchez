
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include "card.h"

using namespace std;

bool findNextMatch(const CardList& player_list, const CardList& opponent_list, Card& match) {
    try {
        Card current = player_list.getMin();
        do {
            if (opponent_list.find(current)) {
                match = current;
                return true;
            }
            current = player_list.getNext(current);
        } while (true);
    } catch (...) {
        return false;
    }
    return false;
}

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
    bool found_any_match = false;
    Card match("", "");

    while (!alice_cards.empty() && !bob_cards.empty()) {
        bool found_match = false;
        
        if (alice_turn) {
            found_match = findNextMatch(alice_cards, bob_cards, match);
            if (found_match) {
                cout << "Alice picked matching card " << match << endl;
                alice_cards.remove(match);
                bob_cards.remove(match);
                found_any_match = true;
            }
        } else {
            found_match = findNextMatch(bob_cards, alice_cards, match);
            if (found_match) {
                cout << "Bob picked matching card " << match << endl;
                bob_cards.remove(match);
                alice_cards.remove(match);
                found_any_match = true;
            }
        }
        
        if (!found_match) {
            break;
        }
        
        alice_turn = !alice_turn;
    }

    if (found_any_match) {
        cout << endl;
    }

    cout << "Alice's cards:" << endl;
    alice_cards.print();

    cout << endl << "Bob's cards:" << endl;
    bob_cards.print();

    return 0;
}