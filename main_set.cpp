// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file#include <iostream>
#include <fstream>
#include <set>
#include "card.h"

using namespace std;

void read_cards(ifstream& file, set<Card>& cards) {
    char suit;
    string value;
    while (file >> suit >> value) {
        cards.insert(Card(suit, value));
    }
}

void play_game(set<Card>& alice, set<Card>& bob) {
    auto alice_it = alice.begin();
    while (alice_it != alice.end()) {
        if (bob.find(*alice_it) != bob.end()) {
            cout << "Alice picked matching card " << *alice_it << endl;
            bob.erase(*alice_it);
            alice_it = alice.erase(alice_it);
        } else {
            ++alice_it;
        }
    }

    auto bob_it = bob.rbegin();
    while (bob_it != bob.rend()) {
        if (alice.find(*bob_it) != alice.end()) {
            cout << "Bob picked matching card " << *bob_it << endl;
            alice.erase(*bob_it);
            auto to_erase = next(bob_it).base();
            bob_it = make_reverse_iterator(bob.erase(to_erase));
        } else {
            ++bob_it;
        }
    }

    cout << "Alice's cards:" << endl;
    for (const auto& card : alice) {
        cout << card << endl;
    }

    cout << "Bob's cards:" << endl;
    for (const auto& card : bob) {
        cout << card << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <alice_cards.txt> <bob_cards.txt>" << endl;
        return 1;
    }

    ifstream alice_file(argv[1]);
    ifstream bob_file(argv[2]);

    if (!alice_file.is_open() || !bob_file.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    set<Card> alice_cards, bob_cards;
    read_cards(alice_file, alice_cards);
    read_cards(bob_file, bob_cards);

    play_game(alice_cards, bob_cards);

    return 0;
}
