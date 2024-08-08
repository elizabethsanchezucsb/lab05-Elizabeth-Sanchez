#include "card.h"

Card::Card(Suit s, int v) : suit(s), value(v) {}

bool Card::operator<(const Card& other) const {
    if (suit != other.suit) return suit < other.suit;
    return value < other.value;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

bool Card::operator>(const Card& other) const {
    if (suit != other.suit) return suit > other.suit;
    return value > other.value;
}
