#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    enum Suit { CLUBS, DIAMONDS, SPADES, HEARTS };
    enum Value { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

    // Constructor
    Card(Suit s, Value v);

    // Method to convert card to string
    std::string toString() const;

    // Comparison operators
    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator>(const Card& other) const;

private:
    Suit suit;
    Value value;
};

#endif // CARD_H
