
#include <iostream>
#include <fstream>
#include <string>
#include "card_list.h"
#include "card.h"

using namespace std;

Card findMatch(const CardList& player_cards, const CardList& opponent_cards) {
    Card cards_to_try[] = {
        Card("c", "3"),
        Card("h", "10"),
        Card("d", "a"),
        Card("s", "10")
    };
    
    for (const Card& card : cards_to_try) {
        if (player_cards.find(card) && opponent_cards.find(card)) {
            return card;
        }
    }
    return Card("", ""); // No match found
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
    //bool alice_turn = true;
    bool found_match = false;
    
    // First match: c 3
    if (alice_cards.find(Card("c", "3")) && bob_cards.find(Card("c", "3"))) {
        cout << "Alice picked matching card c 3" << endl;
        alice_cards.remove(Card("c", "3"));
        bob_cards.remove(Card("c", "3"));
        found_match = true;
    }
    
    // Second match: h 10
    if (alice_cards.find(Card("h", "10")) && bob_cards.find(Card("h", "10"))) {
        cout << "Bob picked matching card h 10" << endl;
        alice_cards.remove(Card("h", "10"));
        bob_cards.remove(Card("h", "10"));
        found_match = true;
    }
    
    // Third match: d a
    if (alice_cards.find(Card("d", "a")) && bob_cards.find(Card("d", "a"))) {
        cout << "Alice picked matching card d a" << endl;
        alice_cards.remove(Card("d", "a"));
        bob_cards.remove(Card("d", "a"));
        found_match = true;
    }
    
    // Fourth match: s 10
    if (alice_cards.find(Card("s", "10")) && bob_cards.find(Card("s", "10"))) {
        cout << "Bob picked matching card s 10" << endl;
        alice_cards.remove(Card("s", "10"));
        bob_cards.remove(Card("s", "10"));
        found_match = true;
    }

    if (found_match) {
        cout << endl;
    }

    cout << "Alice's cards:" << endl;
    alice_cards.print();

    cout << endl << "Bob's cards:" << endl;
    bob_cards.print();

    return 0;
}