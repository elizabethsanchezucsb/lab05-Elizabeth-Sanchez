#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class BSTNode {
public:
    Card data;        // The card stored in this node
    BSTNode* left;    // Pointer to the left child
    BSTNode* right;   // Pointer to the right child

    // Constructor to initialize a node with a card
    BSTNode(const Card& card);
};

class BST {
private:
    BSTNode* root;   // Pointer to the root of the tree

    // Helper function to insert a card into the BST
    void insert(BSTNode*& node, const Card& card);

    // Helper function to find a card in the BST
    BSTNode* find(BSTNode* node, const Card& card) const;

    // Helper function to remove a card from the BST
    void remove(BSTNode*& node, const Card& card);

    // Helper function to get the minimum card in the BST
    BSTNode* getMin(BSTNode* node) const;

    // Helper function to delete the entire tree
    void clear(BSTNode* node);

    // Helper function to print the tree in order
    void printInOrder(BSTNode* node) const;

public:
    // Constructor and destructor
    BST();
    ~BST();

    // Public methods
    void insert(const Card& card);
    BSTNode* find(const Card& card) const;
    void remove(const Card& card);
    void printInOrder() const;
    BSTNode* successor(BSTNode* node) const;
    BSTNode* predecessor(BSTNode* node) const;
};

#endif // CARD_LIST_H
