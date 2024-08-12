#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "card.h"

void readCardsFromFile(const std::string& filename, std::set<Card>& cards) {
    std::ifstream file(filename);
    char suit;
    std::string rank;
    while (file >> suit >> rank) {
        cards.insert(Card(suit, rank));
    }
}

void printCards(const std::set<Card>& cards) {
    for (const auto& card : cards) {
        std::cout << card.suit << " " << card.rank << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    std::set<Card> aliceCards;
    std::set<Card> bobCards;

    readCardsFromFile(argv[1], aliceCards);
    readCardsFromFile(argv[2], bobCards);

    bool matchFound = true;
    while (matchFound) {
        matchFound = false;

        // Alice's turn
        for (auto it = aliceCards.begin(); it != aliceCards.end(); ) {
            if (bobCards.find(*it) != bobCards.end()) {
                std::cout << "Alice picked matching card " << it->suit << " " << it->rank << std::endl;
                bobCards.erase(*it);
                it = aliceCards.erase(it);
                matchFound = true;
            } else {
                ++it;
            }
        }

        // Bob's turn
        for (auto it = bobCards.rbegin(); it != bobCards.rend(); ) {
            if (aliceCards.find(*it) != aliceCards.end()) {
                std::cout << "Bob picked matching card " << it->suit << " " << it->rank << std::endl;
                aliceCards.erase(*it);
                it = std::set<Card>::reverse_iterator(bobCards.erase(std::next(it).base()));
                matchFound = true;
            } else {
                ++it;
            }
        }
    }

    std::cout << "\nAlice's cards:" << std::endl;
    printCards(aliceCards);

    std::cout << "\nBob's cards:" << std::endl;
    printCards(bobCards);

    return 0;
}