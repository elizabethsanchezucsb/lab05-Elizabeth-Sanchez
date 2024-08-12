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

     if (alice_turn(node->left, bob)) return true;

     if (bob.find(node->data)) {
        cout << "Alice picked matching card " << node->data << endl;
        bob.remove(node->data);
        return true;
    }

     return alice_turn(node->right, bob);
}

// Helper function for reverse in-order traversal and finding matches for Bob
bool bob_turn(Node* node, CardBST& alice) {
    if (!node) return false;

     if (bob_turn(node->right, alice)) return true;

     if (alice.find(node->data)) {
        cout << "Bob picked matching card " << node->data << endl;
        alice.remove(node->data);
        return true;
    }

     return bob_turn(node->left, alice);
}

void play_game(CardBST& alice, CardBST& bob) {
    bool found_match;
    do {
        // Alice's turn
        found_match = alice_turn(alice.get_root(), bob);

        // If Alice found a match bob gets a turn
        if (found_match) {
            found_match = bob_turn(bob.get_root(), alice);
        }
    } while (found_match); 
    // Continues until no matches are found

    cout << "Alice's cards:" << endl;
    alice.in_order_traversal();

    cout << "Bob's cards:" << endl;
    bob.in_order_traversal();
}
int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){

  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){

  }
  cardFile2.close();
  
  
  return 0;
}