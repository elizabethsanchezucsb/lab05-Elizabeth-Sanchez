#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    char suit;
    int value;

public:
    Card(char s, int v);
    char getSuit() const;
    int getValue() const;
    std::string toString() const;

    // Overload comparison operators
    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
};

#endif // CARD_H