// card_list.cpp
#include "card_list.h"

void CardList::insert(Node*& node, Card card) {
    if (node == nullptr) {
        node = new Node(card);
    } else if (card < node->card) {
        insert(node->left, card);
    } else {
        insert(node->right, card);
    }
}

bool CardList::find(Node* node, Card card) const {
    if (node == nullptr) {
        return false;
    } else if (node->card == card) {
        return true;
    } else if (card < node->card) {
        return find(node->left, card);
    } else {
        return find(node->right, card);
    }
}

void CardList::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void CardList::insert(Card card) {
    insert(root, card);
}

bool CardList::find(Card card) const {
    return find(root, card);
}