#include <iostream>
#include <fstream>
#include <set>
#include "card_list.h"

// Function to read cards from a file into a BST
BST readCardsFromFile(const std::string& filename) {
    BST cards;
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
bool aliceTurn(BST& aliceCards, BST& bobCards) {
    bool matchFound = false;

    // Using in-order traversal to iterate through Alice's cards
    std::set<Card> aliceCardsSet;
    std::ifstream file("alice_cards.txt");
    std::string suitChar;
    int value;
    while (file >> suitChar >> value) {
        Card::Suit suit;
        if (suitChar == "c") suit = Card::CLUBS;
        else if (suitChar == "d") suit = Card::DIAMONDS;
        else if (suitChar == "s") suit = Card::SPADES;
        else if (suitChar == "h") suit = Card::HEARTS;
        
        aliceCardsSet.insert(Card(suit, value));
    }
    file.close();

    for (const auto& card : aliceCardsSet) {
        if (bobCards.find(card)) {
            std::cout << "Alice picked matching card " << card << std::endl;
            bobCards.remove(card);  // Remove the card from Bob's hand
            aliceCards.remove(card);  // Remove the card from Alice's hand
            matchFound = true;  // A match was found
        }
    }

    return matchFound;
}

// Function to handle Bob's turn
bool bobTurn(BST& aliceCards, BST& bobCards) {
    bool matchFound = false;

    // Using in-order traversal to iterate through Bob's cards in reverse order
    std::set<Card> bobCardsSet;
    std::ifstream file("bob_cards.txt");
    std::string suitChar;
    int value;
    while (file >> suitChar >> value) {
        Card::Suit suit;
        if (suitChar == "c") suit = Card::CLUBS;
        else if (suitChar == "d") suit = Card::DIAMONDS;
        else if (suitChar == "s") suit = Card::SPADES;
        else if (suitChar == "h") suit = Card::HEARTS;
        
        bobCardsSet.insert(Card(suit, value));
    }
    file.close();

    for (auto it = bobCardsSet.rbegin(); it != bobCardsSet.rend(); ++it) {
        if (aliceCards.find(*it)) {
            std::cout << "Bob picked matching card " << *it << std::endl;
            aliceCards.remove(*it);  // Remove the card from Alice's hand
            bobCards.remove(*it);  // Remove the card from Bob's hand
            matchFound = true;  // A match was found
        }
    }

    return matchFound;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards.txt> <bob_cards.txt>" << std::endl;
        return 1;
    }

    // Read the cards from input files
    BST aliceCards = readCardsFromFile(argv[1]);
    BST bobCards = readCardsFromFile(argv[2]);

    bool matchFound = true;

    // The game loop continues as long as matches are found
while (matchFound) {
        matchFound = aliceTurn(aliceCards, bobCards);
        if (matchFound) {
            matchFound = bobTurn(aliceCards, bobCards);
        }
    }

    // Print the final hands of Alice and Bob
    std::cout << "\nAlice's cards:" << std::endl;
    aliceCards.printInOrder();

    std::cout << "\nBob's cards:" << std::endl;
    bobCards.printInOrder();

    return 0;
}        
