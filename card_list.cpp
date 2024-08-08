#include "card_list.h"
#include <iostream>

CardNode::CardNode(const Card& c) : data(c), left(nullptr), right(nullptr) {}

CardBST::CardBST() : root(nullptr) {}

CardBST::~CardBST() {
    destroy_tree(root);
}

void CardBST::insert(CardNode*& node, const Card& c) {
    if (node == nullptr) {
        node = new CardNode(c);
    } else if (c < node->data) {
        insert(node->left, c);
    } else if (node->data < c) {
        insert(node->right, c);
    }
}

void CardBST::insert(const Card& c) {
    insert(root, c);
}

CardNode* CardBST::find(CardNode* node, const Card& c) const {
    if (node == nullptr) return nullptr;
    if (node->data == c) return node;
    if (c < node->data) return find(node->left, c);
    return find(node->right, c);
}

bool CardBST::find(const Card& c) const {
    return find(root, c) != nullptr;
}

void CardBST::inorder_print(CardNode* node) const {
    if (node) {
        inorder_print(node->left);
        std::cout << node->data.suit << " " << node->data.value << "\n";
        inorder_print(node->right);
    }
}

void CardBST::print_inorder() const {
    inorder_print(root);
}

void CardBST::destroy_tree(CardNode* node) {
    if (node) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }
}
