#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "card.h"

void load_cards(const std::string& filename, std::set<Card>& hand) {
    std::ifstream file(filename);
    std::string suit_str;
    std::string value_str;
    while (file >> suit_str >> value_str) {
        Suit suit;
        if (suit_str == "c") suit = CLUBS;
        else if (suit_str == "d") suit = DIAMONDS;
        else if (suit_str == "s") suit = SPADES;
        else suit = HEARTS;

        int value;
        if (value_str == "a") value = 1;
        else if (value_str == "j") value = 11;
        else if (value_str == "q") value = 12;
        else if (value_str == "k") value = 13;
        else value = std::stoi(value_str);

        hand.insert(Card(suit, value));
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_file> <bob_file>" << std::endl;
        return 1;
    }

    std::set<Card> alice_hand;
    std::set<Card> bob_hand;

    load_cards(argv[1], alice_hand);
    load_cards(argv[2], bob_hand);

    std::cout << "Alice's cards:\n";
    for (const auto& card : alice_hand) {
        std::cout << card.suit << " " << card.value << "\n";
    }

    std::cout << "Bob's cards:\n";
    for (const auto& card : bob_hand) {
        std::cout << card.suit << " " << card.value << "\n";
    }

    return 0;
}
