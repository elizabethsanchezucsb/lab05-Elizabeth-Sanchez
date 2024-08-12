// card.h
// Author: Elizabeth Sanchez
// All class declarations related to defining a single card go here
#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    enum class Suit { CLUBS, DIAMONDS, SPADES, HEARTS };
    enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

    Card(Suit s, Rank r);
    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
    Suit getSuit() const;
    Rank getRank() const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Suit suit;
    Rank rank;
};

#endif
