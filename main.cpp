// Feb 14: This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
#include <iostream>
#include <fstream>
#include "card_list.h"
#include "card.h"

using namespace std;

void read_cards(ifstream& file, CardBST& cards) {
    char suit;
    string value;
    while (file >> suit >> value) {
        cards.insert(Card(suit, value));
    }
}

// Helper function for in-order traversal and finding matches for Alice
bool alice_turn(Node* node, CardBST& bob) {
    if (!node) return false;

    // Traverse the left subtree
    if (alice_turn(node->left, bob)) return true;

    // Check current node
    if (bob.find(node->data)) {
        cout << "Alice picked matching card " << node->data << endl;
        bob.remove(node->data);
        return true;
    }

    // Traverse the right subtree
    return alice_turn(node->right, bob);
}

// Helper function for reverse in-order traversal and finding matches for Bob
bool bob_turn(Node* node, CardBST& alice) {
    if (!node) return false;

    // Traverse the right subtree
    if (bob_turn(node->right, alice)) return true;

    // Check current node
    if (alice.find(node->data)) {
        cout << "Bob picked matching card " << node->data << endl;
        alice.remove(node->data);
        return true;
    }

    // Traverse the left subtree
    return bob_turn(node->left, alice);
}

void play_game(CardBST& alice, CardBST& bob) {
    bool found_match;
    do {
        // Alice's turn
        found_match = alice_turn(alice.get_root(), bob);

        // If Alice found a match, Bob gets a turn
        if (found_match) {
            found_match = bob_turn(bob.get_root(), alice);
        }
    } while (found_match); // Continue until no matches are found

    cout << "Alice's cards:" << endl;
    alice.in_order_traversal();

    cout << "Bob's cards:" << endl;
    bob.in_order_traversal();
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

    CardBST alice_cards, bob_cards;
    read_cards(alice_file, alice_cards);
    read_cards(bob_file, bob_cards);

    play_game(alice_cards, bob_cards);

    return 0;
}
