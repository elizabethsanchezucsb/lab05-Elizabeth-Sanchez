#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    enum Suit { CLUBS, DIAMONDS, SPADES, HEARTS };
    Card(Suit s = CLUBS, int v = 1);
    
    Suit getSuit() const;
    int getValue() const;
    
    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator>(const Card& other) const;
    
    std::string toString() const;

private:
    Suit suit;
    int value;
};

#endif // CARD_H
