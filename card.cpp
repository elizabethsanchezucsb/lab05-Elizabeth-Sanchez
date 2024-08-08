#include "card.h"
#include <sstream>

Card::Card(char s, int v) : suit(s), value(v) {}

char Card::getSuit() const {
    return suit;
}

int Card::getValue() const {
    return value;
}

std::string Card::toString() const {
    std::ostringstream oss;
    oss << value << suit;
    return oss.str();
}

bool Card::operator<(const Card& other) const {
    if (suit == other.suit) {
        return value < other.value;
    }
    return suit < other.suit;
}

bool Card::operator==(const Card& other) const {
    return (suit == other.suit) && (value == other.value);
}