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
