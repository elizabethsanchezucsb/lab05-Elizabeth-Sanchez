// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h

#include "card.h"

// Constructor
Card::Card(const string& suit, int value) : suit(suit), value(value) {}

// Operator <
bool Card::operator<(const Card& other) const {
    if (suit == other.suit) {
        return value < other.value;
    }
    return suit < other.suit;
}

// Operator >
bool Card::operator>(const Card& other) const {
    if (suit == other.suit) {
        return value > other.value;
    }
    return suit > other.suit;
}

// Operator ==
bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

// Operator <<
ostream& operator<<(ostream& os, const Card& card) {
    os << card.suit << " " << card.value;
    return os;
}
