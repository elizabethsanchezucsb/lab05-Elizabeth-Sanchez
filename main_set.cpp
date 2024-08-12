#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "card.h"

// Helper function to convert suit character to Suit enum
Card::Suit charToSuit(char suitChar) {
    switch (suitChar) {
        case 'c': return Card::Suit::CLUBS;
        case 'd': return Card::Suit::DIAMONDS;
        case 's': return Card::Suit::SPADES;
        case 'h': return Card::Suit::HEARTS;
        default: throw std::invalid_argument("Invalid suit");
    }
}

// Helper function to convert rank string to Rank enum
Card::Rank stringToRank(const std::string& rankStr) {
    if (rankStr == "a") return Card::Rank::ACE;
    if (rankStr == "j") return Card::Rank::JACK;
    if (rankStr == "q") return Card::Rank::QUEEN;
    if (rankStr == "k") return Card::Rank::KING;
    int rankNum = std::stoi(rankStr);
    if (rankNum >= 2 && rankNum <= 10) {
        return static_cast<Card::Rank>(rankNum);
    }
    throw std::invalid_argument("Invalid rank");
}

void readCardsFromFile(const std::string& filename, std::set<Card>& cards) {
    std::ifstream file(filename);
    char suitChar;
    std::string rankStr;
    while (file >> suitChar >> rankStr) {
        try {
            Card::Suit suit = charToSuit(suitChar);
            Card::Rank rank = stringToRank(rankStr);
            cards.insert(Card(suit, rank));
        } catch (const std::invalid_argument&) {
            std::cerr << "Invalid card in file: " << suitChar << " " << rankStr << std::endl;
        }
    }
}

void printCards(const std::set<Card>& cards) {
    for (const auto& card : cards) {
        std::cout << card << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    std::set<Card> aliceCards, bobCards;
    readCardsFromFile(argv[1], aliceCards);
    readCardsFromFile(argv[2], bobCards);

    bool matchFound;
    do {
        matchFound = false;

        // Alice's turn
        for (auto it = aliceCards.begin(); it != aliceCards.end(); ) {
            if (bobCards.find(*it) != bobCards.end()) {
                std::cout << "Alice picked matching card " << *it << std::endl;
                bobCards.erase(*it);
                it = aliceCards.erase(it);
                matchFound = true;
                break;
            } else {
                ++it;
            }
        }

        if (!matchFound) {
            // Bob's turn
            for (auto it = bobCards.rbegin(); it != bobCards.rend(); ++it) {
                if (aliceCards.find(*it) != aliceCards.end()) {
                    std::cout << "Bob picked matching card " << *it << std::endl;
                    aliceCards.erase(*it);
                    it = std::set<Card>::reverse_iterator(bobCards.erase(std::next(it).base()));
                    matchFound = true;
                    break;
                }
            }
        }
    } while (matchFound);

    std::cout << "\nAlice's cards:" << std::endl;
    printCards(aliceCards);

    std::cout << "\nBob's cards:" << std::endl;
    printCards(bobCards);

    return 0;
}