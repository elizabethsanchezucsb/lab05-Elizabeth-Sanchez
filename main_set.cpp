#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include "card.h"

// Function to read cards from a file into a set
void readCardsFromFile(const std::string& filename, std::set<Card>& cards) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    std::string suitStr;
    std::string valueStr;
    while (file >> suitStr >> valueStr) {
        Card::Suit suit;
        Card::Value value;
        
        // Convert suit string to enum
        if (suitStr == "c") suit = Card::CLUBS;
        else if (suitStr == "d") suit = Card::DIAMONDS;
        else if (suitStr == "s") suit = Card::SPADES;
        else if (suitStr == "h") suit = Card::HEARTS;
        else {
            std::cerr << "Unknown suit: " << suitStr << std::endl;
            continue;
        }

        // Convert value string to enum
        if (valueStr == "a") value = Card::ACE;
        else if (valueStr == "2") value = Card::TWO;
        else if (valueStr == "3") value = Card::THREE;
        else if (valueStr == "4") value = Card::FOUR;
        else if (valueStr == "5") value = Card::FIVE;
        else if (valueStr == "6") value = Card::SIX;
        else if (valueStr == "7") value = Card::SEVEN;
        else if (valueStr == "8") value = Card::EIGHT;
        else if (valueStr == "9") value = Card::NINE;
        else if (valueStr == "10") value = Card::TEN;
        else if (valueStr == "j") value = Card::JACK;
        else if (valueStr == "q") value = Card::QUEEN;
        else if (valueStr == "k") value = Card::KING;
        else {
            std::cerr << "Unknown value: " << valueStr << std::endl;
            continue;
        }

        cards.insert(Card(suit, value));
    }
}

// Function to print a set of cards
void printCardSet(const std::set<Card>& cards) {
    for (const auto& card : cards) {
        std::cout << card.toString() << std::endl;
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    // Read cards from files
    std::set<Card> aliceCards;
    std::set<Card> bobCards;
    
    readCardsFromFile(argv[1], aliceCards);
    readCardsFromFile(argv[2], bobCards);

    // Game logic
    std::set<Card> aliceRemaining = aliceCards;
    std::set<Card> bobRemaining = bobCards;

    bool aliceTurn = true;
    while (!aliceRemaining.empty() && !bobRemaining.empty()) {
        if (aliceTurn) {
            // Alice's turn
            for (auto it = aliceRemaining.begin(); it != aliceRemaining.end(); ) {
                if (bobRemaining.find(*it) != bobRemaining.end()) {
                    std::cout << "Alice picked matching card " << it->toString() << std::endl;
                    bobRemaining.erase(*it);
                    it = aliceRemaining.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
        } else {
            // Bob's turn
            for (auto it = bobRemaining.rbegin(); it != bobRemaining.rend(); ) {
                if (aliceRemaining.find(*it) != aliceRemaining.end()) {
                    std::cout << "Bob picked matching card " << it->toString() << std::endl;
                    aliceRemaining.erase(*it);
                    it = std::reverse_iterator<std::set<Card>::iterator>(bobRemaining.erase(std::next(it).base()));
                    break;
                } else {
                    ++it;
                }
            }
        }
        aliceTurn = !aliceTurn;
    }

    // Print final hands
    std::cout << "\nAlice's cards:" << std::endl;
    printCardSet(aliceRemaining);

    std::cout << "\nBob's cards:" << std::endl;
    printCardSet(bobRemaining);

    return 0;
}
