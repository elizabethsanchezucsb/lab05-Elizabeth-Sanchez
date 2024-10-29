// card.h
// Author: Your name
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card{
    public:
    Card(string suit, string value);
    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;

    string suit;
    string value;

    //constructor to define so default

    //bool operator<(const Card& other) const{ //other reppresents original Card class
    //return value < other.value || (value == other.value && suit < other.suit);
    private:
    int getValue() const;
    int getSuitValue() const;
    int getOrderValue() const;

    };

    ostream& operator<<(ostream& os, const Card& card);



#endif