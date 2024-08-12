
#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class Node {
public:
    Card data;
    Node* left;
    Node* right;

    Node(const Card& card) : data(card), left(nullptr), right(nullptr) {}
};

class CardBST {
public:
    CardBST();
    ~CardBST();

    void insert(const Card& card);
    bool find(const Card& card) const;
    void remove(const Card& card);
    void in_order_traversal() const;
    Node* get_root() const;  // New function to get root node

private:
    Node* root;

    void insert(Node*& node, const Card& card);
    bool find(Node* node, const Card& card) const;
    Node* remove(Node* node, const Card& card);
    Node* find_min(Node* node) const;
    void in_order_traversal(Node* node) const;
    void clear(Node* node);
};

#endif // CARD_LIST_H

 game
 Download
 main.cpp
 Download
 main_set.cpp
 Download
#include <iostream>
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

 o_0.txt
 Download
 o_1.txt
 Download
 o_2.txt
 Download
 o_3.txt
 Download
 tests.cpp
 Download
#include <iostream>
#include <cassert>
#include "card.h"
#include "card_list.h"

void testInsert() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.contains(Card("c", "a")));
    assert(cl.contains(Card("d", "2")));
    assert(cl.contains(Card("h", "k")));
    assert(cl.contains(Card("s", "5")));

    std::cout << "testInsert passed." << std::endl;
}

void testDelete() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    cl.remove(Card("d", "2"));
    assert(!cl.contains(Card("d", "2")));

    cl.remove(Card("h", "k"));
    assert(!cl.contains(Card("h", "k")));

    std::cout << "testDelete passed." << std::endl;
}

void testFind() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.contains(Card("c", "a")));
    assert(cl.contains(Card("d", "2")));
    assert(cl.contains(Card("h", "k")));
    assert(cl.contains(Card("s", "5")));
    assert(!cl.contains(Card("d", "3")));

    std::cout << "testFind passed." << std::endl;
}

void testSuccessor() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.successor(Card("c", "a")) == Card("d", "2"));
    assert(cl.successor(Card("d", "2")) == Card("s", "5"));
    assert(cl.successor(Card("s", "5")) == Card("h", "k"));
    assert(cl.successor(Card("h", "k")).suit == "" && cl.successor(Card("h", "k")).value == "");

    std::cout << "testSuccessor passed." << std::endl;
}

void testPredecessor() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.predecessor(Card("h", "k")) == Card("s", "5"));
    assert(cl.predecessor(Card("s", "5")) == Card("d", "2"));
    assert(cl.predecessor(Card("d", "2")) == Card("c", "a"));
    assert(cl.predecessor(Card("c", "a")).suit == "" && cl.predecessor(Card("c", "a")).value == "");

    std::cout << "testPredecessor passed." << std::endl;
}

int main() {
    testInsert();
    testDelete();
    testFind();
    testSuccessor();
    testPredecessor();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
