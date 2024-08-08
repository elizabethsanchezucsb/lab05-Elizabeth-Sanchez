#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class Node {
public:
    Node(const Card& card);
    Card card;
    Node* left;
    Node* right;
};

class CardList {
public:
    CardList();
    ~CardList();
    
    void insert(const Card& card);
    bool find(const Card& card) const;
    void remove(const Card& card);
    void printInOrder() const;
    void printReverseInOrder() const;

private:
    Node* root;
    void insert(Node*& node, const Card& card);
    bool find(Node* node, const Card& card) const;
    Node* remove(Node* node, const Card& card);
    Node* minValueNode(Node* node) const;
    void printInOrder(Node* node) const;
    void printReverseInOrder(Node* node) const;
    void destroyTree(Node* node);
};

#endif // CARD_LIST_H
