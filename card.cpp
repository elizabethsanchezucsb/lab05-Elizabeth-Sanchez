#include "card.h"

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

bool Card::operator<(const Card& other) const {
    if (suit < other.suit) return true;
    if (suit > other.suit) return false;
    return value < other.value;
}

bool Card::operator>(const Card& other) const {
    if (suit > other.suit) return true;
    if (suit < other.suit) return false;
    return value > other.value;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const char* suits[] = {"Clubs", "Diamonds", "Spades", "Hearts"};
    const char* values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    os << values[card.value - 1] << " of " << suits[card.suit];
    return os;
}
