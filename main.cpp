#include <iostream>
#include <fstream>
#include "card_list.h"
#include "card.h"

void printCard(const Card& card) {
    std::cout << card.getSuit() << " " << card.getValue() << std::endl;
}

void processCardList(const std::string& filename, CardList& cardList) {
    std::ifstream file(filename);
    std::string suit;
    std::string value;

    while (file >> suit >> value) {
        Card card(suit, value);
        cardList.addCard(card);
    }
}

int main() {
    CardList aliceCards;
    CardList bobCards;

    processCardList("alice.txt", aliceCards);
    processCardList("bob.txt", bobCards);

    std::cout << "Alice's cards:" << std::endl;
    aliceCards.inOrderTraversal(printCard);

    std::cout << "Bob's cards:" << std::endl;
    bobCards.inOrderTraversal(printCard);

    std::cout << "Matching cards:" << std::endl;

    // To store cards that are in both lists
    std::set<Card> matchingCards;

    // Iterate through Alice's cards and check if they are in Bob's card list
    aliceCards.inOrderTraversal([&](const Card& aliceCard) {
        bobCards.inOrderTraversal([&](const Card& bobCard) {
            if (aliceCard == bobCard) {
                matchingCards.insert(aliceCard);
            }
        });
    });

    for (const auto& card : matchingCards) {
        std::cout << "Matching card: " << card.getSuit() << " " << card.getValue() << std::endl;
    }

    return 0;
}
