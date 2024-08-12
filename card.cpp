
// card.cpp
// Author: Elizabeth Sanchez
// Implementation of the classes defined in card.h
#include "card.h"

Card::Card(Suit s, Rank r) : suit(s), rank(r) {}

bool Card::operator<(const Card& other) const {
    if (suit != other.suit) {
        return static_cast<int>(suit) < static_cast<int>(other.suit);
    }
    return static_cast<int>(rank) < static_cast<int>(other.rank);
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && rank == other.rank;
}

Card::Suit Card::getSuit() const { return suit; }
Card::Rank Card::getRank() const { return rank; }

std::ostream& operator<<(std::ostream& os, const Card& card) {
    char suitChar;
    switch (card.suit) {
        case Card::Suit::CLUBS: suitChar = 'c'; break;
        case Card::Suit::DIAMONDS: suitChar = 'd'; break;
        case Card::Suit::SPADES: suitChar = 's'; break;
        case Card::Suit::HEARTS: suitChar = 'h'; break;
    }

    std::string rankStr;
    switch (card.rank) {
        case Card::Rank::ACE: rankStr = "a"; break;
        case Card::Rank::JACK: rankStr = "j"; break;
        case Card::Rank::QUEEN: rankStr = "q"; break;
        case Card::Rank::KING: rankStr = "k"; break;
        default: rankStr = std::to_string(static_cast<int>(card.rank));
    }

    os << suitChar << " " << rankStr;
    return os;
}