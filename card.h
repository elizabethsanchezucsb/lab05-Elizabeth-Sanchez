#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
    char suit;  // c, d, s, h
    string value;  // a, 2, 3, ..., 10, j, q, k

    Card();
    Card(char s, const string& v);

    bool operator<(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator>(const Card& other) const;

    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif // CARD_H
