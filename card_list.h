#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"

struct TreeNode {
    Card card;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Card& c) : card(c), left(nullptr), right(nullptr) {}
};

class CardList {
private:
    TreeNode* root;

    void insert(TreeNode*& node, const Card& card);
    void destroyTree(TreeNode* node);

public:
    CardList();
    ~CardList();

    void insert(const Card& card);
    bool find(const Card& card) const;
    void printInOrder() const;
    TreeNode* getRoot() const;
};

#endif // CARD_LIST_H
