// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"

Card::Card(std::string suit, int value) : suit(suit), value(value) {}

bool Card::operator<(const Card& other) const {
    if (this->value == other.value) {
        return this->suit < other.suit;
    }
    return this->value < other.value;
}

bool Card::operator==(const Card& other) const {
    return (this->suit == other.suit) && (this->value == other.value);
}

int Card::getValue() const {
    return value;
}