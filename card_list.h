#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

class CardNode {
public:
    Card data;
    CardNode* left;
    CardNode* right;

    CardNode(const Card& c);
};

class CardBST {
private:
    CardNode* root;

    void insert(CardNode*& node, const Card& c);
    void inorder_print(CardNode* node) const;
    CardNode* find(CardNode* node, const Card& c) const;  // Private helper
    void destroy_tree(CardNode* node);

public:
    CardBST();
    ~CardBST();

    void insert(const Card& c);
    bool find(const Card& c) const;  // Public interface
    void print_inorder() const;
};

#endif
