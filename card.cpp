// card.cpp
#include "card.h"

Card::Card(char suit, const std::string& value) : suit(suit), value(value) {}

std::string Card::toString() const {
    return std::string(1, suit) + " " + value;
}

bool Card::operator<(const Card& other) const {
    if (suit != other.suit) {
        return suit < other.suit;
    }
    // Convert value to int for comparison, with special cases for face cards
    auto getValue = [](const std::string& v) {
        if (v == "a") return 1;
        if (v == "j") return 11;
        if (v == "q") return 12;
        if (v == "k") return 13;
        return std::stoi(v);
    };
    return getValue(value) < getValue(other.value);
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}