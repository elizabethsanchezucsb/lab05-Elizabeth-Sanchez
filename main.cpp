
#include "card.h"
#include "card_list.h"
#include <iostream>
#include <fstream>

void readCards(const std::string& filename, CardList& cards) {
    std::ifstream file(filename);
    char suit, value;
    while (file >> suit >> value) {
        cards.insert(Card(suit, value));
    }
}

void playGame(CardList& aliceCards, CardList& bobCards) {
    CardList aliceMatches;
    CardList bobMatches;

    // Find matches for Alice
    for (char suit = 'a'; suit <= 'z'; ++suit) {
        for (char value = '1'; value <= '9'; ++value) {
            Card card(suit, value);
            if (aliceCards.find(card) && bobCards.find(card)) {
                aliceMatches.insert(card);
                bobCards.remove(card);
            }
        }
    }

    // Find matches for Bob
    for (char suit = 'a'; suit <= 'z'; ++suit) {
        for (char value = '1'; value <= '9'; ++value) {
            Card card(suit, value);
            if (bobCards.find(card) && aliceCards.find(card)) {
                bobMatches.insert(card);
                aliceCards.remove(card);
            }
        }
    }

    std::cout << "Alice picked matching cards: ";
    aliceMatches.print();

    std::cout << "Bob picked matching cards: ";
    bobMatches.print();

    std::cout << "Alice's remaining cards: ";
    aliceCards.print();

    std::cout << "Bob's remaining cards: ";
    bobCards.print();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    CardList aliceCards;
    CardList bobCards;

    readCards(argv[1], aliceCards);
    readCards(argv[2], bobCards);

    playGame(aliceCards, bobCards);

    return 0;
}