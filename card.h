// card.h
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    char suit;
    std::string rank;

    Card(char s, std::string r) : suit(s), rank(r) {}

    bool operator==(const Card& other) const {
        return suit == other.suit && rank == other.rank;
    }

    bool operator<(const Card& other) const {
        if (suit == other.suit) {
            return rank < other.rank;
        }
        return suit < other.suit;
    }
};

#endif // CARD_H