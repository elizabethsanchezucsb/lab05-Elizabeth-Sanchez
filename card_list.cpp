#include "card_list.h"
#include <iostream>

Node::Node(const Card& c) : card(c), left(nullptr), right(nullptr) {}

CardList::CardList() : root(nullptr) {}

CardList::~CardList() {
    destroyTree(root);
}

void CardList::insert(const Card& card) {
    insert(root, card);
}

bool CardList::find(const Card& card) const {
    return find(root, card);
}

void CardList::remove(const Card& card) {
    root = remove(root, card);
}

void CardList::printInOrder() const {
    printInOrder(root);
    std::cout << std::endl;
}

void CardList::printReverseInOrder() const {
    printReverseInOrder(root);
    std::cout << std::endl;
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

bool CardList::find(Node* node, const Card& card) const {
    if (node == nullptr) {
        return false;
    } else if (card == node->card) {
        return true;
    } else if (card < node->card) {
        return find(node->left, card);
    } else {
        return find(node->right, card);
    }
}

Node* CardList::remove(Node* node, const Card& card) {
    if (node == nullptr) {
        return node;
    }
    
    if (card < node->card) {
        node->left = remove(node->left, card);
    } else if (card > node->card) {
        node->right = remove(node->right, card);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        Node* temp = minValueNode(node->right);
        node->card = temp->card;
        node->right = remove(node->right, temp->card);
    }
    return node;
}

Node* CardList::minValueNode(Node* node) const {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void CardList::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << node->card.toString() << std::endl;
        printInOrder(node->right);
    }
}

void CardList::printReverseInOrder(Node* node) const {
    if (node) {
        printReverseInOrder(node->right);
        std::cout << node->card.toString() << std::endl;
        printReverseInOrder(node->left);
    }
}

void CardList::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
