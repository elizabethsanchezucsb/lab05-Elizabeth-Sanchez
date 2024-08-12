#include "card.h"

Card::Card(Suit suit, Value value) : suit(suit), value(value) {}

Card::Suit Card::getSuit() const {
    return suit;
}

Card::Value Card::getValue() const {
    return value;
}

bool Card::operator<(const Card& other) const {
    if (suit != other.suit) {
        return suit < other.suit;
    }
    return value < other.value;
}
