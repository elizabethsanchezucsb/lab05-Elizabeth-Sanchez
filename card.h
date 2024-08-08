#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string suit;
    std::string value;

public:
    Card(const std::string& suit = "", const std::string& value = "");

    std::string getSuit() const;
    std::string getValue() const;

    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
};

#endif // CARD_H
