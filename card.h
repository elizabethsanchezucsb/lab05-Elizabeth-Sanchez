
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card();
    Card(char suit, char value);
    std::string toString() const;
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;

private:
    char suit;
    char value;
    int getValue() const;
};

#endif // CARD_H