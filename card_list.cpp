#include "card_list.h"
#include <iostream>

CardList::CardList() : root(nullptr) {}

CardList::~CardList() {
    destroyTree(root);
}

void CardList::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void CardList::insert(const Card& card) {
    insert(root, card);
}

void CardList::insert(TreeNode*& node, const Card& card) {
    if (!node) {
        node = new TreeNode(card);
    } else if (card < node->card) {
        insert(node->left, card);
    } else if (card > node->card) {
        insert(node->right, card);
    }
}

bool CardList::find(const Card& card) const {
    TreeNode* current = root;
    while (current) {
        if (card == current->card) {
            return true;
        } else if (card < current->card) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void CardList::printInOrder() const {
    struct StackNode {
        TreeNode* treeNode;
        StackNode* next;
    };
    
    StackNode* stack = nullptr;
    TreeNode* current = root;

    while (current || stack) {
        while (current) {
            stack = new StackNode{current, stack};
            current = current->left;
        }
        
        if (stack) {
            current = stack->treeNode;
            std::cout << current->card << std::endl;
            StackNode* temp = stack;
            stack = stack->next;
            delete temp;
            current = current->right;
        }
    }
}

TreeNode* CardList::getRoot() const {
    return root;
}
