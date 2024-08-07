// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h
#include "card_list.h"
#include <vector>

void CardList::insert(const Card& card) {
    insert(root, card);
}

void CardList::insert(Node*& node, const Card& card) {
    if (!node) {
        node = new Node(card);
    } else if (card < node->card) {
        insert(node->left, card);
    } else if (card > node->card) {
        insert(node->right, card);
    }
}

bool CardList::find(const Card& card) const {
    return find(root, card);
}

bool CardList::find(Node* node, const Card& card) const {
    if (!node) return false;
    if (card == node->card) return true;
    if (card < node->card) return find(node->left, card);
    return find(node->right, card);
}

void CardList::remove(const Card& card) {
    root = remove(root, card);
}

CardList::Node* CardList::remove(Node* node, const Card& card) {
    if (!node) return nullptr;
    if (card < node->card) {
        node->left = remove(node->left, card);
    } else if (card > node->card) {
        node->right = remove(node->right, card);
    } else {
        if (!node->left) {
            Node* rightNode = node->right;
            delete node;
            return rightNode;
        }
        if (!node->right) {
            Node* leftNode = node->left;
            delete node;
            return leftNode;
        }
        Node* minNode = findMin(node->right);
        node->card = minNode->card;
        node->right = remove(node->right, minNode->card);
    }
    return node;
}

CardList::Node* CardList::findMin(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

CardList::Node* CardList::findMax(Node* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

void CardList::inOrderTraversal(Node* node, std::vector<Card>& cards) const {
    if (node) {
        inOrderTraversal(node->left, cards);
        cards.push_back(node->card);
        inOrderTraversal(node->right, cards);
    }
}

void CardList::reverseInOrderTraversal(Node* node, std::vector<Card>& cards) const {
    if (node) {
        reverseInOrderTraversal(node->right, cards);
        cards.push_back(node->card);
        reverseInOrderTraversal(node->left, cards);
    }
}

CardList::Iterator CardList::begin() const {
    std::vector<Card> cards;
    inOrderTraversal(root, cards);
    return Iterator(cards.cbegin());
}

CardList::Iterator CardList::end() const {
    std::vector<Card> cards;
    inOrderTraversal(root, cards);
    return Iterator(cards.cend());
}

CardList::Iterator CardList::rbegin() const {
    std::vector<Card> cards;
    reverseInOrderTraversal(root, cards);
    return Iterator(cards.cbegin());
}

CardList::Iterator CardList::rend() const {
    std::vector<Card> cards;
    reverseInOrderTraversal(root, cards);
    return Iterator(cards.cend());
}

void CardList::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
