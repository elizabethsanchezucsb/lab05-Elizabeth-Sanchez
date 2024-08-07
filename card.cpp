// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h

#include "card.h"

Card::Card(const string& suit, int value) : suit(suit), value(value) {}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

bool Card::operator<(const Card& other) const {
    if (suit < other.suit) return true;
    if (suit > other.suit) return false;
    return value < other.value;
}

bool Card::operator>(const Card& other) const {
    return !(*this < other) && !(*this == other);
}

ostream& operator<<(ostream& os, const Card& card) {
    os << card.suit << " " << card.value;
    return os;
}
