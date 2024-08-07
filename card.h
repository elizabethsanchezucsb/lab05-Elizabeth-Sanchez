// card.h
// Author: Your name
// All class declarations related to defining a single card go here
#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
public:
    string suit;
    int value;

    Card(const string& suit, int value);
    
    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;

    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif
