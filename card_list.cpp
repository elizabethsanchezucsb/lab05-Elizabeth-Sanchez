// card_list.cpp
#include "card_list.h"
#include <iostream>

// Add the missing deleteTree implementation
void CardList::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void CardList::insertHelper(Node*& node, const Card& card) {
    if (!node) {
        node = new Node(card);
        return;
    }
    if (card < node->card) {
        insertHelper(node->left, card);
    } else if (node->card < card) {
        insertHelper(node->right, card);
    }
}

void CardList::insert(const Card& card) {
    insertHelper(root, card);
}

bool CardList::findHelper(Node* node, const Card& card) const {
    if (!node) return false;
    if (card == node->card) return true;
    if (card < node->card) return findHelper(node->left, card);
    return findHelper(node->right, card);
}

bool CardList::find(const Card& card) const {
    return findHelper(root, card);
}

CardList::Node* CardList::findMin(Node* node) const {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

void CardList::removeHelper(Node*& node, const Card& card) {
    if (!node) return;
    
    if (card < node->card) {
        removeHelper(node->left, card);
    } else if (node->card < card) {
        removeHelper(node->right, card);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            node = temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            node = temp;
        } else {
            Node* temp = findMin(node->right);
            node->card = temp->card;
            removeHelper(node->right, temp->card);
        }
    }
}

void CardList::remove(const Card& card) {
    removeHelper(root, card);
}

void CardList::printHelper(Node* node, std::ostream& os) const {
    if (!node) return;
    printHelper(node->left, os);
    os << node->card << std::endl;
    printHelper(node->right, os);
}

void CardList::print(std::ostream& os) const {
    printHelper(root, os);
}

std::vector<Card> CardList::getAllCards() const {
    std::vector<Card> cards;
    getAllCardsHelper(root, cards);
    return cards;
}

void CardList::getAllCardsHelper(Node* node, std::vector<Card>& cards) const {
    if (!node) return;
    getAllCardsHelper(node->left, cards);
    cards.push_back(node->card);
    getAllCardsHelper(node->right, cards);
}