// card_list.cpp
// Author: Elizabeth sanchez
// Implementation of the classes defined in card_list.h#include "card_list.h"
#include <iostream>
#include "card.h"


CardBST::CardBST() : root(nullptr) {}

CardBST::~CardBST() {
    clear(root);
}

void CardBST::insert(const Card& card) {
    insert(root, card);
}

void CardBST::insert(Node*& node, const Card& card) {
    if (!node) {
        node = new Node(card);
    } else if (card < node->data) {
        insert(node->left, card);
    } else if (card > node->data) {
        insert(node->right, card);
    }
}

bool CardBST::find(const Card& card) const {
    return find(root, card);
}

bool CardBST::find(Node* node, const Card& card) const {
    if (!node) {
        return false;
    }
    if (card == node->data) {
        return true;
    }
    if (card < node->data) {
        return find(node->left, card);
    }
    return find(node->right, card);
}

void CardBST::remove(const Card& card) {
    root = remove(root, card);
}

Node* CardBST::remove(Node* node, const Card& card) {
    if (!node) return nullptr;

    if (card < node->data) {
        node->left = remove(node->left, card);
    } else if (card > node->data) {
        node->right = remove(node->right, card);
    } else {
        if (!node->left) {
            Node* right = node->right;
            delete node;
            return right;
        } else if (!node->right) {
            Node* left = node->left;
            delete node;
            return left;
        } else {
            Node* min_node = find_min(node->right);
            node->data = min_node->data;
            node->right = remove(node->right, min_node->data);
        }
    }
    return node;
}

Node* CardBST::find_min(Node* node) const {
    while (node->left) {
        node = node->left;
    }
    return node;
}

void CardBST::in_order_traversal() const {
    in_order_traversal(root);
}

void CardBST::in_order_traversal(Node* node) const {
    if (node) {
        in_order_traversal(node->left);
        std::cout << node->data << std::endl;
        in_order_traversal(node->right);
    }
}

void CardBST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

Node* CardBST::get_root() const {
    return root;
}
