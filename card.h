#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    enum Suit { Clubs, Diamonds, Hearts, Spades };
    enum Value { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

    Card(Suit suit, Value value);

    Suit getSuit() const;
    Value getValue() const;

    // Overload comparison operators
    bool operator<(const Card& other) const;

private:
    Suit suit;
    Value value;
};

#endif // CARD_H
