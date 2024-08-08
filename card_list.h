#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <set>

class CardList {
private:
    std::set<Card> cards; // Using set to maintain ordered cards

public:
    void addCard(const Card& card);
    void inOrderTraversal(void (*visit)(const Card&)) const;
    void reverseInOrderTraversal(void (*visit)(const Card&)) const;
};

#endif // CARD_LIST_H
