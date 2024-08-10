// card_list.h
#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class Node {
public:
    Card card;
    Node* left;
    Node* right;

    Node(Card c) : card(c), left(nullptr), right(nullptr) {}
};

class CardList {
private:
    Node* root;

    void insert(Node*& node, Card card);
    bool find(Node* node, Card card) const;
    void clear(Node* node);

public:
    CardList() : root(nullptr) {}
    ~CardList() { clear(root); }

    void insert(Card card);
    bool find(Card card) const;
};

#endif // CARD_LIST_H