// card.h
// Author: Your name
// All class declarations related to defining a single card go here
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
private:
    string suit;
    int value;

public:
    Card(const string& suit, int value);
    
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;

    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif
