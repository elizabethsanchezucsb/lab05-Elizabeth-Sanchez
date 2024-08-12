#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    char suit;
    std::string rank;

    Card(char s, const std::string& r) : suit(s), rank(r) {}

    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;

private:
    int getSuitValue() const;
    int getRankValue() const;
};

#endif