#include "card.h"

Card::Card(const std::string& suit, const std::string& value) : suit(suit), value(value) {}

std::string Card::getSuit() const {
    return suit;
}

std::string Card::getValue() const {
    return value;
}

bool Card::operator<(const Card& other) const {
    if (suit < other.suit) return true;
    if (suit == other.suit && value < other.value) return true;
    return false;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}
