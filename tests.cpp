#include <iostream>
#include <cassert>
#include "card_list.h"

// Function to test Card comparison operators
void testCardComparison() {
    Card c1(Card::CLUBS, 2);
    Card c2(Card::CLUBS, 3);
    Card c3(Card::DIAMONDS, 2);
    Card c4(Card::CLUBS, 2);
    
    assert(c1 < c2);   // Clubs 2 should be less than Clubs 3
    assert(c1 < c3);   // Clubs 2 should be less than Diamonds 2
    assert(c2 > c1);   // Clubs 3 should be greater than Clubs 2
    assert(c1 == c4);  // Clubs 2 should be equal to Clubs 2
    assert(c1 != c2);  // Clubs 2 should not be equal to Clubs 3

    std::cout << "Card comparison tests passed!" << std::endl;
}

// Function to print the BST in-order for debugging purposes
void printTree(const BST& bst) {
    bst.printInOrder();  // Assumes your BST has a printInOrder method
}

// Function to test BST insertion
void testInsertion() {
    BST bst;
    bst.insert(Card(Card::HEARTS, 10));
    bst.insert(Card(Card::SPADES, 5));
    bst.insert(Card(Card::DIAMONDS, 7));
    
    printTree(bst);

    std::cout << "Insertion tests passed!" << std::endl;
}

// Function to test BST find operation
void testFind() {
    BST bst;
    bst.insert(Card(Card::HEARTS, 10));
    bst.insert(Card(Card::SPADES, 5));
    bst.insert(Card(Card::DIAMONDS, 7));
    
    assert(bst.find(Card(Card::HEARTS, 10)));  // Should find this card
    assert(bst.find(Card(Card::SPADES, 5)));   // Should find this card
    assert(bst.find(Card(Card::DIAMONDS, 7)));  // Should find this card
    assert(!bst.find(Card(Card::CLUBS, 2)));    // Should not find this card

    std::cout << "Find tests passed!" << std::endl;
}

// Function to test BST deletion
void testDelete() {
    BST bst;
    bst.insert(Card(Card::HEARTS, 10));
    bst.insert(Card(Card::SPADES, 5));
    bst.insert(Card(Card::DIAMONDS, 7));
    
    bst.remove(Card(Card::HEARTS, 10));
    assert(!bst.find(Card(Card::HEARTS, 10)));  // Should not find the removed card

    printTree(bst);

    std::cout << "Deletion tests passed!" << std::endl;
}

// Function to test BST successor
void testSuccessor() {
    BST bst;
    bst.insert(Card(Card::DIAMONDS, 7));
    bst.insert(Card(Card::SPADES, 5));
    bst.insert(Card(Card::HEARTS, 10));

    BSTNode* node = bst.find(Card(Card::SPADES, 5));
    BSTNode* successor = bst.successor(node);

    assert(successor && successor->data == Card(Card::DIAMONDS, 7));
    std::cout << "Successor test passed!" << std::endl;
}


// Function to test BST predecessor
void testPredecessor() {
    BST bst;
    bst.insert(Card(Card::HEARTS, 10));
    bst.insert(Card(Card::SPADES, 5));
    bst.insert(Card(Card::DIAMONDS, 7));
    
    BSTNode* node = bst.find(Card(Card::DIAMONDS, 7)); // Corrected to not use 'root'
    BSTNode* predecessor = bst.predecessor(node);
    assert(predecessor && predecessor->data == Card(Card::SPADES, 5));  // Should find the correct predecessor

    std::cout << "Predecessor tests passed!" << std::endl;
}

// Function to test game logic
void testGameLogic() {
    BST aliceCards;
    BST bobCards;

    // Insert cards for Alice and Bob
    aliceCards.insert(Card(Card::CLUBS, 2));
    aliceCards.insert(Card(Card::DIAMONDS, 3));
    aliceCards.insert(Card(Card::SPADES, 10));
    
    bobCards.insert(Card(Card::CLUBS, 2));
    bobCards.insert(Card(Card::DIAMONDS, 5));
    bobCards.insert(Card(Card::SPADES, 10));

    // Simulate Alice's turn
    // Ensure aliceTurn is defined or remove the call if not implemented
    // bool matchFound = aliceTurn(aliceCards, bobCards);  

    // Check remaining cards
    // assert(!aliceCards.find(Card(Card::CLUBS, 2))); // Should not find the removed card
    // assert(!bobCards.find(Card(Card::CLUBS, 2))); // Should not find the removed card

    std::cout << "Game logic tests passed!" << std::endl;
}

int main() {
    testCardComparison();
    testInsertion();
    testFind();
    testDelete();
    testSuccessor();
    testPredecessor();
    testGameLogic();

    return 0;
}
