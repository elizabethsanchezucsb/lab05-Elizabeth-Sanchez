#include <iostream>
#include <fstream>
#include <set>
#include <string>

// Assuming Suit enum is defined somewhere
enum Suit {
    CLUBS,
    DIAMONDS,
    SPADES,
    HEARTS
};

std::istream& operator>>(std::istream& in, Suit& suit) {
    std::string str;
    in >> str;

    if (str == "CLUBS") suit = CLUBS;
    else if (str == "DIAMONDS") suit = DIAMONDS;
    else if (str == "SPADES") suit = SPADES;
    else if (str == "HEARTS") suit = HEARTS;
    else in.setstate(std::ios::failbit);

    return in;
}

struct Card {
    Suit suit;
    int value;
    // Define the necessary comparison operators for set to work correctly.
    bool operator<(const Card& other) const {
        return (suit < other.suit) || (suit == other.suit && value < other.value);
    }
};

void loadCardsFromFile(const std::string& filename, std::set<Card>& cardSet) {
    std::ifstream file(filename);
    Suit suit;
    int value;

    while (file >> suit >> value) {
        cardSet.insert(Card{suit, value});
    }
}

int main() {
    std::set<Card> cardSet;
    loadCardsFromFile("cards.txt", cardSet);

    for (const auto& card : cardSet) {
        std::cout << card.suit << " " << card.value << std::endl;
    }

    return 0;
}
