#include <iostream>
#include <fstream>
#include <set>
#include "card.h"

void playGame(std::set<Card>& aliceCards, std::set<Card>& bobCards);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    std::set<Card> aliceCards;
    std::set<Card> bobCards;

    std::ifstream aliceFile(argv[1]);
    std::ifstream bobFile(argv[2]);

    if (!aliceFile || !bobFile) {
        std::cerr << "Error opening input files." << std::endl;
        return 1;
    }

    char suit;
    std::string value;
    while (aliceFile >> suit >> value) {
        Card::Suit cardSuit;
        if (suit == 'c') cardSuit = Card::CLUBS;
        else if (suit == 'd') cardSuit = Card::DIAMONDS;
        else if (suit == 's') cardSuit = Card::SPADES;
        else if (suit == 'h') cardSuit = Card::HEARTS;

        int cardValue;
        if (value == "a") cardValue = 1;
        else if (value == "j") cardValue = 11;
        else if (value == "q") cardValue = 12;
        else if (value == "k") cardValue = 13;
        else cardValue = std::stoi(value);

        aliceCards.insert(Card(cardSuit, cardValue));
    }

    while (bobFile >> suit >> value) {
        Card::Suit cardSuit;
        if (suit == 'c') cardSuit = Card::CLUBS;
        else if (suit == 'd') cardSuit = Card::DIAMONDS;
        else if (suit == 's') cardSuit = Card::SPADES;
        else if (suit == 'h') cardSuit = Card::HEARTS;

        int cardValue;
        if (value == "a") cardValue = 1;
        else if (value == "j") cardValue = 11;
        else if (value == "q") cardValue = 12;
        else if (value == "k") cardValue = 13;
        else cardValue = std::stoi(value);

        bobCards.insert(Card(cardSuit, cardValue));
    }

    playGame(aliceCards, bobCards);

    return 0;
}

 
void playGame(std::set<Card>& aliceCards, std::set<Card>& bobCards) {
    std::cout << "Alice's cards:" << std::endl;
    for (const auto& card : aliceCards) {
        std::cout << card.toString() << std::endl;
    }
    
    std::cout << "Bob's cards:" << std::endl;
    for (const auto& card : bobCards) {
        std::cout << card.toString() << std::endl;
    }

    std::cout << "Matching cards:" << std::endl;
    for (const auto& card : aliceCards) {
        if (bobCards.find(card) != bobCards.end()) {
            std::cout << card.toString() << std::endl;
        }
    }
}

