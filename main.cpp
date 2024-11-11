
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include "card.h"

using namespace std;

bool findFirstMatch(const CardList& player_cards, const CardList& opponent_cards, Card& match_card) {
    try {
        Card current = player_cards.getMin();
        while (true) {
            if (opponent_cards.find(current)) {
                match_card = current;
                return true;
            }
            try {
                current = player_cards.getNext(current);
            } catch (...) {
                break;
            }
        }
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
    Card match_card("", "");
    bool any_matches = false;
    CardList alice_temp = alice_cards;
    CardList bob_temp = bob_cards;

    while (!alice_temp.empty() && !bob_temp.empty()) {
        bool found_match = false;
        
        if (alice_turn) {
            if (findFirstMatch(alice_temp, bob_temp, match_card)) {
                cout << "Alice picked matching card " << match_card << endl;
                alice_cards.remove(match_card);
                bob_cards.remove(match_card);
                alice_temp.remove(match_card);
                bob_temp.remove(match_card);
                found_match = true;
                any_matches = true;
            }
        } else {
            if (findFirstMatch(bob_temp, alice_temp, match_card)) {
                cout << "Bob picked matching card " << match_card << endl;
                alice_cards.remove(match_card);
                bob_cards.remove(match_card);
                alice_temp.remove(match_card);
                bob_temp.remove(match_card);
                found_match = true;
                any_matches = true;
            }
        }
        
        if (!found_match) {
            break;
        }
        
        alice_turn = !alice_turn;
    }

    if (any_matches) {
        cout << endl;
    }

    cout << "Alice's cards:" << endl;
    alice_cards.print();

    cout << endl << "Bob's cards:" << endl;
    bob_cards.print();

    return 0;
}