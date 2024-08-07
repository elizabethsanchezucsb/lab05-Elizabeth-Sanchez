#include "card.h"

Card::Card() : suit('c'), value("a") {}

Card::Card(char s, const string& v) : suit(s), value(v) {}

bool Card::operator<(const Card& other) const {
    if (suit == other.suit) {
        return value < other.value;
    }
    return suit < other.suit;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

bool Card::operator>(const Card& other) const {
    if (suit == other.suit) {
        return value > other.value;
    }
    return suit > other.suit;
}

ostream& operator<<(ostream& os, const Card& card) {
    os << card.suit << " " << card.value;
    return os;
}
