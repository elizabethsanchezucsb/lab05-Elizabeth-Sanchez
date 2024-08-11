#include <iostream>
#include <fstream>
#include <set>
#include "card.h"

// Function to read cards from a file into a set
std::set<Card> readCardsFromFile(const std::string& filename) {
    std::set<Card> cards;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string suitChar;
        int value;
        while (file >> suitChar >> value) {
            Card::Suit suit;
            if (suitChar == "c") suit = Card::CLUBS;
            else if (suitChar == "d") suit = Card::DIAMONDS;
            else if (suitChar == "s") suit = Card::SPADES;
            else if (suitChar == "h") suit = Card::HEARTS;

            cards.insert(Card(suit, value));
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return cards;
}

// Function to handle Alice's turn
bool aliceTurn(std::set<Card>& aliceCards, std::set<Card>& bobCards) {
    for (auto it = aliceCards.begin(); it != aliceCards.end(); ++it) {
        if (bobCards.find(*it) != bobCards.end()) {
            std::cout << "Alice picked matching card " << *it << std::endl;
            bobCards.erase(*it);  // Remove the card from Bob's hand
            aliceCards.erase(it);  // Remove the card from Alice's hand
            return true;  // Return true indicating a match was found
        }
    }
    return false;  // No match found
}

// Function to handle Bob's turn
bool bobTurn(std::set<Card>& aliceCards, std::set<Card>& bobCards) {
    for (auto it = bobCards.rbegin(); it != bobCards.rend(); ++it) {
        if (aliceCards.find(*it) != aliceCards.end()) {
            std::cout << "Bob picked matching card " << *it << std::endl;
            aliceCards.erase(*it);  // Remove the card from Alice's hand
            bobCards.erase(--(it.base()));  // Remove the card from Bob's hand (adjusting for reverse iterator)
            return true;  // Return true indicating a match was found
        }
    }
    return false;  // No match found
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards.txt> <bob_cards.txt>" << std::endl;
        return 1;
    }

    // Read the cards from input files
    std::set<Card> aliceCards = readCardsFromFile(argv[1]);
    std::set<Card> bobCards = readCardsFromFile(argv[2]);

    bool matchFound = true;

    // The game loop continues as long as matches are found
    while (matchFound) {
        matchFound = aliceTurn(aliceCards, bobCards);  // Alice's turn
        if (matchFound) {
            matchFound = bobTurn(aliceCards, bobCards);  // Bob's turn
        }
    }

    // Print the final hands of both players
    std::cout << "\nAlice's cards:" << std::endl;
    for (const auto& card : aliceCards) {
        std::cout << card << std::endl;
    }

    std::cout << "\nBob's cards:" << std::endl;
    for (const auto& card : bobCards) {
        std::cout << card << std::endl;
    }

    return 0;
}
