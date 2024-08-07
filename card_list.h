// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand


#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>

class CardList {
public:
    CardList();
    ~CardList();
    
    void insert(const Card& card);
    bool remove(const Card& card);
    bool find(const Card& card) const;
    
    void printInOrder() const;

private:
    struct Node {
        Card card;
        Node* left;
        Node* right;
        Node(const Card& c) : card(c), left(nullptr), right(nullptr) {}
    };
    
    Node* root;

    void insert(Node*& node, const Card& card);
    bool remove(Node*& node, const Card& card);
    bool find(Node* node, const Card& card) const;
    void printInOrder(Node* node) const;
    void clear(Node* node);
    Node* findMin(Node* node) const;
};



#endif
