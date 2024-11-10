// card_list.h
#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

struct CardNode {
    Card card;
    CardNode* left;
    CardNode* right;
    CardNode(const Card& c) : card(c), left(nullptr), right(nullptr) {}
};

class CardList {
private:
    CardNode* root;

    // Private helper functions
    CardNode* findMin(CardNode* node) const;
    CardNode* findNext(CardNode* node, const Card& card) const;
    void deleteTree(CardNode* node);
    void printInOrder(CardNode* node) const;  // Added this line

public:
    // Constructor and destructor
    CardList() : root(nullptr) {}
    ~CardList();

    // Basic BST operations
    void insert(const Card& card);
    bool find(const Card& card) const;
    void remove(const Card& card);
    void print() const;
    bool empty() const { return root == nullptr; }  // Added empty() function
    
    // Helper functions for game logic
    Card getMin() const;  // Modified to return Card instead of CardNode*
    Card getNext(const Card& card) const;  // Modified to return Card instead of CardNode*
};

#endif