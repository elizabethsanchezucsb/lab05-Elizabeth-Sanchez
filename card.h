// card.h
// Author: Your name
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class card{
    public:
    //enum is distinct type, whose value is restricted to a range of values such as: 
    enum Suit {clubs, diamonds, spades, hearts};

    //constructors
    card(Suit s, int val); //initializes card with type or value?
    card(const string& suit, int value);//this will transform the users string input value type of string s to be represented as enum type, we go from "c","d","s","h" to enum type if input "c" enum type == clubs
    

};

#endif

