#include <iostream>
#include <fstream>
#include "card_list.h"
#include "card.h"

void playGame(CardList& aliceCards, CardList& bobCards);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    CardList aliceCards;
    CardList bobCards;

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

void playGame(CardList& aliceCards, CardList& bobCards) {
    std::cout << "Alice's cards (in order):" << std::endl;
    aliceCards.printInOrder();
    
    std::cout << "Bob's cards (in order):" << std::endl;
    bobCards.printInOrder();

    std::cout << "Matching cards:" << std::endl;
    TreeNode* aliceNode = aliceCards.getRoot();
    
    while (aliceNode) {
        if (bobCards.find(aliceNode->card)) {
            std::cout << aliceNode->card << std::endl;
        }
        // Move to the next node in in-order traversal
        if (aliceNode->right) {
            aliceNode = aliceNode->right;
            while (aliceNode->left) {
                aliceNode = aliceNode->left;
            }
        } else {
            TreeNode* parent = nullptr;
            while (aliceNode && (!parent || aliceNode == parent->right)) {
                aliceNode = parent;
                // You need to track the parent node during traversal to do this correctly
            }
        }
    }
}
