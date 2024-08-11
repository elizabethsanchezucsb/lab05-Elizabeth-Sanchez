#include "card.h"

// Constructor to initialize a card with a suit and value
Card::Card(Suit s, int v) : suit(s), value(v) {}

// Accessor to get the suit of the card
Card::Suit Card::getSuit() const {
    return suit;
}

// Accessor to get the value of the card
int Card::getValue() const {
    return value;
}

// Comparison operator to check if one card is less than another
bool Card::operator<(const Card& other) const {
    // Compare suits first; if they are the same, compare values
    if (suit != other.suit)
        return suit < other.suit;
    return value < other.value;
}

// Comparison operator to check if one card is greater than another
bool Card::operator>(const Card& other) const {
    // Compare suits first; if they are the same, compare values
    if (suit != other.suit)
        return suit > other.suit;
    return value > other.value;
}

// Equality operator to check if two cards are the same
bool Card::operator==(const Card& other) const {
    // Cards are equal if both suit and value match
    return suit == other.suit && value == other.value;
}

// Overload << operator to print a card in a readable format
std::ostream& operator<<(std::ostream& os, const Card& card) {
    const std::string suits[] = {"Clubs", "Diamonds", "Spades", "Hearts"};
    const std::string values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    // Print the card's value and suit
    os << values[card.value - 1] << " of " << suits[card.suit];
    return os;
}
