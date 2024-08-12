#include "card.h"

// Constructor implementation
Card::Card(Suit s, Value v) : suit(s), value(v) {}

// Converts the card to a string representation
std::string Card::toString() const {
    static const std::string suits[] = { "c", "d", "s", "h" };
    static const std::string values[] = { "a", "2", "3", "4", "5", "6", "7", "8", "9", "10", "j", "q", "k" };
    return suits[suit] + " " + values[value - 1];
}

// Comparison operator: less than
bool Card::operator<(const Card& other) const {
    if (suit != other.suit) return suit < other.suit;
    return value < other.value;
}

// Comparison operator: equality
bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

// Comparison operator: greater than
bool Card::operator>(const Card& other) const {
    if (suit != other.suit) return suit > other.suit;
    return value > other.value;
}
