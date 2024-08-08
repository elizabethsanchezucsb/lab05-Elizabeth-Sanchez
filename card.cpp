
#include "card.h"
#include <stdexcept>

Card::Card() : suit('0'), value('0') {}

Card::Card(char s, char v) : suit(s), value(v) {}

std::string Card::toString() const {
    return std::string(1, suit) + " " + std::string(1, value);
}

bool Card::operator==(const Card& other) const {
    return (suit == other.suit && value == other.value);
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

bool Card::operator<(const Card& other) const {
    if (getValue() == other.getValue()) {
        return suit < other.suit;
    }
    return getValue() < other.getValue();
}

bool Card::operator>(const Card& other) const {
    return other < *this;
}

int Card::getValue() const {
    switch(value) {
        case 'a': return 14;
        case 'k': return 13;
        case 'q': return 12;
        case 'j': return 11;
        case '1': return 10; // Assuming '1' represents 10
        default: return value - '0';
    }
}