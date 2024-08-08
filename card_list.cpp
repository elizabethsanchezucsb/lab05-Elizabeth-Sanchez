
#include "card_list.h"
#include <iostream>

CardList::CardList() : root(nullptr) {}

CardList::~CardList() {
    deleteTree(root);
}

void CardList::deleteTree(CardNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void CardList::insert(const Card& c) {
    if (!root) {
        root = new CardNode(c);
        return;
    }

    CardNode* current = root;
    while (true) {
        if (c < current->data) {
            if (!current->left) {
                current->left = new CardNode(c);
                return;
            }
            current = current->left;
        } else if (c > current->data) {
            if (!current->right) {
                current->right = new CardNode(c);
                return;
            }
            current = current->right;
        } else {
            // Card already exists
            return;
        }
    }
}

bool CardList::remove(const Card& c) {
    CardNode* parent = nullptr;
    CardNode* current = root;

    while (current && current->data != c) {
        parent = current;
        if (c < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (!current) return false;

    if (!current->left && !current->right) {
        if (current == root)
            root = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete current;
    } else if (!current->left) {
        if (current == root)
            root = current->right;
        else if (parent->left == current)
            parent->left = current->right;
        else
            parent->right = current->right;
        delete current;
    } else if (!current->right) {
        if (current == root)
            root = current->left;
        else if (parent->left == current)
            parent->left = current->left;
        else
            parent->right = current->left;
        delete current;
    } else {
        CardNode* successor = findMin(current->right);
        Card successorData = successor->data;
        remove(successorData);
        current->data = successorData;
    }

    return true;
}

bool CardList::find(const Card& c) const {
    CardNode* current = root;
    while (current) {
        if (c == current->data)
            return true;
        else if (c < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

void CardList::print() const {
    printInOrder(root);
    std::cout << std::endl;
}

void CardList::printInOrder(CardNode* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << node->data.toString() << " ";
        printInOrder(node->right);
    }
}

Card* CardList::successor(const Card& c) const {
    CardNode* current = root;
    CardNode* successor = nullptr;

    while (current) {
        if (c < current->data) {
            successor = current;
            current = current->left;
        } else if (c > current->data) {
            current = current->right;
        } else {
            if (current->right) {
                return &(findMin(current->right)->data);
            }
            break;
        }
    }

    return successor ? &(successor->data) : nullptr;
}

Card* CardList::predecessor(const Card& c) const {
    CardNode* current = root;
    CardNode* predecessor = nullptr;

    while (current) {
        if (c > current->data) {
            predecessor = current;
            current = current->right;
        } else if (c < current->data) {
            current = current->left;
        } else {
            if (current->left) {
                return &(findMax(current->left)->data);
            }
            break;
        }
    }

    return predecessor ? &(predecessor->data) : nullptr;
}

CardNode* CardList::findMin(CardNode* node) const {
    while (node->left) {
        node = node->left;
    }
    return node;
}

CardNode* CardList::findMax(CardNode* node) const {
    while (node->right) {
        node = node->right;
    }
    return node;
}