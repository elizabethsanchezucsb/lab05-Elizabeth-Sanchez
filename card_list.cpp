// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"

// Constructor
CardList::CardList() : root(nullptr) {}

// Destructor
CardList::~CardList() {
    clear(root);
}

// Insert a card into the BST
void CardList::insert(const Card& card) {
    insert(root, card);
}

void CardList::insert(Node*& node, const Card& card) {
    if (node == nullptr) {
        node = new Node(card);
    } else if (card < node->card) {
        insert(node->left, card);
    } else if (card > node->card) {
        insert(node->right, card);
    }
}

// Remove a card from the BST
bool CardList::remove(const Card& card) {
    return remove(root, card);
}

bool CardList::remove(Node*& node, const Card& card) {
    if (node == nullptr) {
        return false;
    }
    if (card < node->card) {
        return remove(node->left, card);
    } else if (card > node->card) {
        return remove(node->right, card);
    } else {
        // Node found
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->card = temp->card;
            remove(node->right, temp->card);
        }
        return true;
    }
}

// Find a card in the BST
bool CardList::find(const Card& card) const {
    return find(root, card);
}

bool CardList::find(Node* node, const Card& card) const {
    if (node == nullptr) {
        return false;
    }
    if (card == node->card) {
        return true;
    } else if (card < node->card) {
        return find(node->left, card);
    } else {
        return find(node->right, card);
    }
}

// Print cards in order
void CardList::printInOrder() const {
    printInOrder(root);
}

void CardList::printInOrder(Node* node) const {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->card << std::endl;
        printInOrder(node->right);
    }
}

// Clear the BST
void CardList::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Find the minimum node
CardList::Node* CardList::findMin(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
