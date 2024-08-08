#include "card_list.h"
#include <iostream>

void CardList::addCard(const Card& card) {
    cards.insert(card);
}

void CardList::inOrderTraversal(void (*visit)(const Card&)) const {
    for (const auto& card : cards) {
        visit(card);
    }
}

void CardList::reverseInOrderTraversal(void (*visit)(const Card&)) const {
    // Reverse iteration is not directly supported by std::set, so we use a reverse iterator
    for (auto it = cards.rbegin(); it != cards.rend(); ++it) {
        visit(*it);
    }
}
