#include "card_list.h"
#include <iostream>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear(root);
}

void BST::insert(BSTNode*& node, const Card& card) {
    if (node == nullptr) {
        node = new BSTNode(card);
    } else if (card < node->data) {
        insert(node->left, card);
    } else {
        insert(node->right, card);
    }
}

void BST::insert(const Card& card) {
    insert(root, card);
}

BSTNode* BST::find(BSTNode* node, const Card& card) const {
    if (node == nullptr) return nullptr;
    if (card == node->data) return node;
    if (card < node->data) return find(node->left, card);
    return find(node->right, card);
}

bool BST::find(const Card& card) const {
    return find(root, card) != nullptr;
}

void BST::remove(BSTNode*& node, const Card& card) {
    if (node == nullptr) return;

    if (card < node->data) {
        remove(node->left, card);
    } else if (node->data < card) {
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

void BST::remove(const Card& card) {
    remove(root, card);
}

BSTNode* BST::getMin(BSTNode* node) const {
    while (node && node->left) node = node->left;
    return node;
}

BSTNode* BST::getMax(BSTNode* node) const {
    while (node && node->right) node = node->right;
    return node;
}

BSTNode* BST::getSuccessor(BSTNode* node) const {
    if (node->right != nullptr) {
        return getMin(node->right);
    }

    BSTNode* parent = nullptr;
    BSTNode* current = root;
    while (current != nullptr) {
        if (node->data < current->data) {
            parent = current;
            current = current->left;
        } else if (current->data < node->data) {
            current = current->right;
        } else {
            break;
        }
    }

    return parent;
}

BSTNode* BST::getPredecessor(BSTNode* node) const {
    if (node->left != nullptr) {
        return getMax(node->left);
    }

    BSTNode* parent = nullptr;
    BSTNode* current = root;
    while (current != nullptr) {
        if (node->data < current->data) {
            current = current->left;
        } else if (current->data < node->data) {
            parent = current;
            current = current->right;
        } else {
            break;
        }
    }

    return parent;
}

void BST::clear(BSTNode* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BST::printInOrder(BSTNode* node) const {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->data.toString() << std::endl;
        printInOrder(node->right);
    }
}

void BST::printInOrder() const {
    printInOrder(root);
}

Card BST::getMin() const {
    BSTNode* node = getMin(root);
    return node ? node->data : Card();
}

Card BST::getMax() const {
    BSTNode* node = getMax(root);
    return node ? node->data : Card();
}

Card BST::getSuccessor(const Card& card) const {
    BSTNode* node = find(root, card);
    BSTNode* succ = getSuccessor(node);
    return succ ? succ->data : Card();
}

Card BST::getPredecessor(const Card& card) const {
    BSTNode* node = find(root, card);
    BSTNode* pred = getPredecessor(node);
    return pred ? pred->data : Card();
}
