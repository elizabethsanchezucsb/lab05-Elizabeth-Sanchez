// card_list.cpp
#include "card_list.h"
#include <iostream>
#include <stdexcept>

// Destructor
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

// Insert a card into the BST
void CardList::insert(const Card& card) {
    CardNode** curr = &root;
    while (*curr) {
        if (card < (*curr)->card) {
            curr = &((*curr)->left);
        } else if ((*curr)->card < card) {
            curr = &((*curr)->right);
        } else {
            return; // Card already exists
        }
    }
    *curr = new CardNode(card);
}

// Find a card in the BST
bool CardList::find(const Card& card) const {
    CardNode* curr = root;
    while (curr) {
        if (card < curr->card) {
            curr = curr->left;
        } else if (curr->card < card) {
            curr = curr->right;
        } else {
            return true;
        }
    }
    return false;
}

// Find minimum card in the tree/subtree
CardNode* CardList::findMin(CardNode* node) const {
    if (!node) return nullptr;
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Get minimum card
Card CardList::getMin() const {
    CardNode* min = findMin(root);
    if (!min) {
        throw std::runtime_error("Empty tree");
    }
    return min->card;
}

// Find next card in order
CardNode* CardList::findNext(CardNode* node, const Card& card) const {
    CardNode* curr = root;
    CardNode* successor = nullptr;
    
    while (curr) {
        if (card < curr->card) {
            successor = curr;
            curr = curr->left;
        } else if (curr->card < card) {
            curr = curr->right;
        } else {
            if (curr->right) {
                return findMin(curr->right);
            }
            return successor;
        }
    }
    return successor;
}

// Get next card
Card CardList::getNext(const Card& card) const {
    CardNode* next = findNext(root, card);
    if (!next) {
        throw std::runtime_error("No successor found");
    }
    return next->card;
}

// Remove a card from the BST
void CardList::remove(const Card& card) {
    CardNode** curr = &root;
    CardNode* temp = nullptr;
    
    // Find the node to remove
    while (*curr && (*curr)->card != card) {
        if (card < (*curr)->card) {
            curr = &((*curr)->left);
        } else {
            curr = &((*curr)->right);
        }
    }
    
    if (!*curr) return; // Card not found
    
    // Case 1: No right child
    if (!(*curr)->right) {
        temp = *curr;
        *curr = (*curr)->left;
        delete temp;
    }
    // Case 2: No left child
    else if (!(*curr)->left) {
        temp = *curr;
        *curr = (*curr)->right;
        delete temp;
    }
    // Case 3: Two children
    else {
        // Find successor (minimum element in right subtree)
        CardNode** successor = &((*curr)->right);
        while ((*successor)->left) {
            successor = &((*successor)->left);
        }
        
        // Copy successor's data
        (*curr)->card = (*successor)->card;
        
        // Remove successor
        temp = *successor;
        *successor = (*successor)->right;
        delete temp;
    }
}

// Print the BST in-order
void CardList::print() const {
    printInOrder(root);
}

void CardList::printInOrder(CardNode* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << node->card << std::endl;
        printInOrder(node->right);
    }
}