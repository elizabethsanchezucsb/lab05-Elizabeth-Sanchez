
#include "card.h"
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

void readCards(const std::string& filename, std::set<Card>& cards) {
    std::ifstream file(filename);
    char suit, value;
    while (file >> suit >> value) {
        cards.insert(Card(suit, value));
    }
}

void playGame(std::set<Card>& aliceCards, std::set<Card>& bobCards) {
    std::vector<Card> aliceMatches;
    std::vector<Card> bobMatches;

    for (const auto& card : aliceCards) {
        if (bobCards.find(card) != bobCards.end()) {
            aliceMatches.push_back(card);
            bobCards.erase(card);
        }
    }

    for (const auto& card : bobCards) {
        if (aliceCards.find(card) != aliceCards.end()) {
            bobMatches.push_back(card);
            aliceCards.erase(card);
        }
    }

    std::cout << "Alice picked matching cards: ";
    for (const auto& card : aliceMatches) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;

    std::cout << "Bob picked matching cards: ";
    for (const auto& card : bobMatches) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;

    std::cout << "Alice's remaining cards: ";
    for (const auto& card : aliceCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;

    std::cout << "Bob's remaining cards: ";
    for (const auto& card : bobCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    std::set<Card> aliceCards;
    std::set<Card> bobCards;

    readCards(argv[1], aliceCards);
    readCards(argv[2], bobCards);

    playGame(aliceCards, bobCards);

    return 0;
}