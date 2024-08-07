// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <vector>

class CardList {
private:
    struct Node {
        Card card;
        Node* left;
        Node* right;
        Node(const Card& c) : card(c), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, const Card& card);
    bool find(Node* node, const Card& card) const;
    Node* remove(Node* node, const Card& card);
    Node* findMin(Node* node);
    Node* findMax(Node* node);

    void inOrderTraversal(Node* node, std::vector<Card>& cards) const;
    void reverseInOrderTraversal(Node* node, std::vector<Card>& cards) const;

public:
    CardList() : root(nullptr) {}
    ~CardList() { clear(root); }

    void insert(const Card& card);
    bool find(const Card& card) const;
    void remove(const Card& card);

    class Iterator {
    private:
        std::vector<Card>::const_iterator it;
    public:
        Iterator(const std::vector<Card>::const_iterator& iterator) : it(iterator) {}
        bool operator!=(const Iterator& other) const { return it != other.it; }
        const Card& operator*() const { return *it; }
        Iterator& operator++() { ++it; return *this; }
    };

    Iterator begin() const;
    Iterator end() const;
    Iterator rbegin() const;
    Iterator rend() const;

    void clear(Node* node);
};

#endif
