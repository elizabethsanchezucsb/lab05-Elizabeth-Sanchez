#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class Node {
public:
    Card data;
    Node* left;
    Node* right;

    Node(const Card& c) : data(c), left(nullptr), right(nullptr) {}
};

class CardList {
private:
    Node* root;

    void deleteTree(Node* node);
    Node* insert(Node* node, const Card& card);
    Node* findMin(Node* node) const;
    Node* deleteNode(Node* node, const Card& card);
    Node* find(Node* node, const Card& card) const;

public:
    CardList() : root(nullptr) {}
    ~CardList();

    void insert(const Card& card);
    void remove(const Card& card);
    bool contains(const Card& card) const;
    Card successor(const Card& card) const;
    Card predecessor(const Card& card) const;
};

#endif // CARD_LIST_H