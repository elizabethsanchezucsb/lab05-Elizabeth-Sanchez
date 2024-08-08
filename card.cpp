#include "card.h"
#include <sstream>
#include <iostream>

Card::Card(Suit s, int v) : suit(s), value(v) {}

Card::Suit Card::getSuit() const {
    return suit;
}

int Card::getValue() const {
    return value;
}

bool Card::operator<(const Card& other) const {
    return (suit < other.suit) || (suit == other.suit && value < other.value);
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

bool Card::operator>(const Card& other) const {
    return !(*this < other) && !(*this == other);
}

std::string Card::toString() const {
    static const char* suits[] = {"c", "d", "s", "h"};
    static const char* values[] = {"a", "2", "3", "4", "5", "6", "7", "8", "9", "10", "j", "q", "k"};
    
    std::ostringstream oss;
    oss << suits[suit] << ' ' << values[value - 1];
    return oss.str();
}
