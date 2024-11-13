// card_list.h
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

    void insertHelper(Node*& node, const Card& card);
    bool findHelper(Node* node, const Card& card) const;
    void removeHelper(Node*& node, const Card& card);
    void printHelper(Node* node, std::ostream& os) const;
    Node* findMin(Node* node) const;
    void deleteTree(Node* node);
    void getAllCardsHelper(Node* node, std::vector<Card>& cards) const;

public:
    CardList() : root(nullptr) {}
    ~CardList() { deleteTree(root); }
    
    void insert(const Card& card);
    bool find(const Card& card) const;
    void remove(const Card& card);
    void print(std::ostream& os) const;
    std::vector<Card> getAllCards() const;
};

#endif