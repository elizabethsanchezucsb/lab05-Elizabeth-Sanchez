// card.h
#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
    
    
    public:
    enum Suit{CLUBS, DIAMONDS, SPADES, HEARTS}; //suit is name? 

    Suit suit; //initiliazing here
    int value; //1 for ace, 11 for jack, 12 for queen, 13 for King

    Card(Suit s, int v); //: suit(s), value(v){}
    //accessors for suit and value
    Suit getSuit() const;
    int getValue() const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;

    friend ostream& operator<<(ostream& os, const Card& card);


//     //operator overloads for comparing cards (like is ace bigger than king soo we use > and < and ==)
//     bool operator<(const Card& otherS) const {
//         //first compare suits; if they are the same, compare values
//         if(suit != otherS.suit){ // if suit not copied correctly?
//             return suit < otherS.suit;
//         }
//         return value < otherS.value; 
//     }

//     bool operator>(const Card& otherS) const{
//         //compare suits if they are the same compare va,ues. 
//         if(suit != otherS.suit){
//             return suit > otherS.suit;
//         }
//         return value > otherS.value;
//     }

//     bool operator==(const Card& otherS)



   
   

// //c d s h a 3 3 9 j k
//     bool operator==(const Card& other) const {
//         return suit == other.suit && rank == other.rank;
//     }

//     bool operator<(const Card& other) const {
//         if (suit == other.suit) {
//             return rank < other.rank;
//         }
//         return suit < other.suit;
//     }

//     bool operator>(const Card& other) const {
//         if (suit == other.suit) {
//             return rank > other.rank;
//         }
//         return suit > other.suit;
//     }
};

#endif // CARD_H