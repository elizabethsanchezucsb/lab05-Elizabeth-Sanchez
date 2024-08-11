#include "card_list.h"
#include <iostream>
#include <cassert>


// Constructor to initialize a node with a card
BSTNode::BSTNode(const Card& card) : data(card), left(nullptr), right(nullptr) {}

// Constructor for BST
BST::BST() : root(nullptr) {}

// Destructor for BST
BST::~BST() {
    clear(root);
}

// Helper function to insert a card into the BST
void BST::insert(BSTNode*& node, const Card& card) {
    if (node == nullptr) {
        node = new BSTNode(card);
    } else if (card < node->data) {
        insert(node->left, card);
    } else if (card > node->data) {
        insert(node->right, card);
    }
}

// Public method to insert a card
void BST::insert(const Card& card) {
    insert(root, card);
}

// Helper function to find a card in the BST
BSTNode* BST::find(BSTNode* node, const Card& card) const {
    if (node == nullptr) {
        return nullptr;
    } else if (card < node->data) {
        return find(node->left, card);
    } else if (card > node->data) {
        return find(node->right, card);
    } else {
        return node; // Card found
    }
}

// Public find method
BSTNode* BST::find(const Card& card) const {
    return find(root, card);
}

// Helper function to remove a card from the BST
void BST::remove(BSTNode*& node, const Card& card) {
    if (node == nullptr) return;

    if (card < node->data) {
        remove(node->left, card);
    } else if (card > node->data) {
        remove(node->right, card);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            BSTNode* temp = getMin(node->right);
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

// Public method to remove a card
void BST::remove(const Card& card) {
    remove(root, card);
}

// Helper function to get the minimum card in the BST
BSTNode* BST::getMin(BSTNode* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Helper function to delete the entire tree
void BST::clear(BSTNode* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Helper function to print the tree in order
void BST::printInOrder(BSTNode* node) const {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->data << std::endl;
        printInOrder(node->right);
    }
}

// Public method to print the tree in order
void BST::printInOrder() const {
    printInOrder(root);
}

// Method to find the successor of a node
BSTNode* BST::successor(BSTNode* node) const {
    if (node == nullptr) {
        return nullptr; // Node not found
    }
    if (node->right != nullptr) {
        // Find the leftmost node in the right subtree
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    } else {
        // Climb up the tree until we find a node that is the left child of its parent
        BSTNode* parent = root;
        BSTNode* successor = nullptr;

        while (parent != nullptr) {
            if (node->data < parent->data) {
                successor = parent;
                parent = parent->left;
            } else if (node->data > parent->data) {
                parent = parent->right;
            } else {
                break;
            }
        }
        return successor;
    }
}

// Method to find the predecessor of a node
BSTNode* BST::predecessor(BSTNode* node) const {
    if (node->left != nullptr) {
        BSTNode* current = node->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }
    BSTNode* predecessor = nullptr;
    BSTNode* ancestor = root;
    while (ancestor != node) {
        if (node->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}
