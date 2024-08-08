
#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class CardNode {
public:
    Card data;
    CardNode* left;
    CardNode* right;
    CardNode(const Card& c) : data(c), left(nullptr), right(nullptr) {}
};

class CardList {
public:
    CardList();
    ~CardList();
    void insert(const Card& c);
    bool remove(const Card& c);
    bool find(const Card& c) const;
    Card* successor(const Card& c) const;
    Card* predecessor(const Card& c) const;
    void print() const;

private:
    CardNode* root;
    void deleteTree(CardNode* node);
    void printInOrder(CardNode* node) const;
    CardNode* findNode(const Card& c) const;
    CardNode* findMin(CardNode* node) const;
    CardNode* findMax(CardNode* node) const;
};

#endif // CARD_LIST_H