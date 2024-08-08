#ifndef CARD_H
#define CARD_H

enum Suit { CLUBS, DIAMONDS, SPADES, HEARTS };

class Card {
public:
    Suit suit;
    int value;

    Card(Suit s = CLUBS, int v = 1);
    
    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator>(const Card& other) const;
};

#endif
