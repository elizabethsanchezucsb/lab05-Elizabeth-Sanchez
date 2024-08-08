#include "card_list.h"
#include <stdexcept>

CardList::~CardList() {
    deleteTree(root);
}

void CardList::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void CardList::insert(const Card& card) {
    root = insert(root, card);
}

Node* CardList::insert(Node* node, const Card& card) {
    if (!node) {
        return new Node(card);
    }

    if (card < node->data) {
        node->left = insert(node->left, card);
    } else if (node->data < card) {
        node->right = insert(node->right, card);
    }

    return node;
}

void CardList::remove(const Card& card) {
    root = deleteNode(root, card);
}

Node* CardList::findMin(Node* node) const {
    while (node->left) {
        node = node->left;
    }
    return node;
}

Node* CardList::deleteNode(Node* node, const Card& card) {
    if (!node) return nullptr;

    if (card < node->data) {
        node->left = deleteNode(node->left, card);
    } else if (node->data < card) {
        node->right = deleteNode(node->right, card);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

bool CardList::contains(const Card& card) const {
    return find(root, card) != nullptr;
}

Node* CardList::find(Node* node, const Card& card) const {
    if (!node || node->data == card) {
        return node;
    }

    if (card < node->data) {
        return find(node->left, card);
    } else {
        return find(node->right, card);
    }
}

Card CardList::successor(const Card& card) const {
    Node* current = root;
    Node* successor = nullptr;

    while (current) {
        if (card < current->data) {
            successor = current;
            current = current->left;
        } else if (current->data < card) {
            current = current->right;
        } else {
            if (current->right) {
                successor = findMin(current->right);
            }
            break;
        }
    }

    if (!successor) {
        throw std::runtime_error("No successor found");
    }

    return successor->data;
}

Card CardList::predecessor(const Card& card) const {
    Node* current = root;
    Node* predecessor = nullptr;

    while (current) {
        if (current->data < card) {
            predecessor = current;
            current = current->right;
        } else if (card < current->data) {
            current = current->left;
        } else {
            if (current->left) {
                predecessor = current->left;
                while (predecessor->right) {
                    predecessor = predecessor->right;
                }
            }
            break;
        }
    }

    if (!predecessor) {
        throw std::runtime_error("No predecessor found");
    }

    return predecessor->data;
}