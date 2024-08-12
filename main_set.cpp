#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "card.h"

// Function to read cards from a file into a std::set
std::set<Card> readCardsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::set<Card> cardSet;
    char suitChar;
    std::string valueStr;

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return cardSet;
    }

    while (file >> suitChar >> valueStr) {
        Suit suit;
        Value value;

        switch (suitChar) {
            case 'c': suit = Suit::CLUBS; break;
            case 'd': suit = Suit::DIAMONDS; break;
            case 's': suit = Suit::SPADES; break;
            case 'h': suit = Suit::HEARTS; break;
            default: continue; // Invalid suit character
        }

        if (valueStr == "a") value = Value::ACE;
        else if (valueStr == "j") value = Value::JACK;
        else if (valueStr == "q") value = Value::QUEEN;
        else if (valueStr == "k") value = Value::KING;
        else value = static_cast<Value>(std::stoi(valueStr));

        cardSet.insert(Card(suit, value));
    }

    return cardSet;
}

// Function to print the final cards of a player
void printCards(const std::set<Card>& cards, const std::string& owner) {
    std::cout << owner << "'s cards:" << std::endl;
    for (const auto& card : cards) {
        std::cout << card << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    // Read cards from files
    std::set<Card> aliceCards = readCardsFromFile(argv[1]);
    std::set<Card> bobCards = readCardsFromFile(argv[2]);

    // Create copies for game processing
    std::set<Card> aliceCardsCopy = aliceCards;
    std::set<Card> bobCardsCopy = bobCards;

    bool matchFound;
    do {
        matchFound = false;

        // Alice's turn
        for (auto it = aliceCardsCopy.begin(); it != aliceCardsCopy.end();) {
            if (bobCards.find(*it) != bobCards.end()) {
                std::cout << "Alice picked matching card " << *it << std::endl;
                bobCards.erase(*it);
                it = aliceCardsCopy.erase(it);
                matchFound = true;
            } else {
                ++it;
            }
        }

        if (!matchFound) break;

        // Bob's turn
        for (auto it = bobCardsCopy.rbegin(); it != bobCardsCopy.rend();) {
            if (aliceCards.find(*it) != aliceCards.end()) {
                std::cout << "Bob picked matching card " << *it << std::endl;
                aliceCards.erase(*it);
                it = std::set<Card>::reverse_iterator(bobCardsCopy.erase(std::next(it).base()));
                matchFound = true;
            } else {
                ++it;
            }
        }

    } while (matchFound);

    // Print final hands
    printCards(aliceCards, "Alice");
    printCards(bobCards, "Bob");

    return 0;
}
