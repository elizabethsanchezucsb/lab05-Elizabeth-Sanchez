#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    enum Suit { CLUBS, DIAMONDS, SPADES, HEARTS };

    Suit suit;
    int value;

    Card(Suit s, int v) : suit(s), value(v) {}

    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
};

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif // CARD_H
