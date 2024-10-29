// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"
#include <iostream>
#include <map>


//both these maps define the order of suits and values. 'suitOrder' maps suits to integers 
map<string, int> suitOrder ={{"c", 0}, {"d", 1}, {"s", 2}, {"h", 3}};
static map<string, int> valueOrder = {{"a", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
    {"j", 11}, {"q", 12}, {"k", 13}
};

Card::Card(std::string suit, string value) : suit(suit), value(value) {}

bool Card::operator<(const Card& other) const {
    if (this->getSuitValue() == other.getSuitValue()) {
        return this->getValue() < other.getValue();
    }
    return this->getSuitValue() < other.getSuitValue();
}
bool Card::operator==(const Card& other) const {
    return (this->suit == other.suit) && (this->value == other.value);
}

int Card::getValue() const {
    return valueOrder[value];

}
int Card::getSuitValue() const {
    return suitOrder[suit];
}
int Card::getOrderValue() const {
    return getSuitValue() * 100 + getValue();
}
ostream& operator<<(ostream& os, const Card& card) {
    os << card.suit + " " + card.value;
    return os;
}