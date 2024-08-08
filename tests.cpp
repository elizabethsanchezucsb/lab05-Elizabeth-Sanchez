#include <iostream>
#include <fstream>
#include <set>
#include "card.h"

// Define this to switch between CardList and std::set implementations
#define USE_CARD_LIST

#ifdef USE_CARD_LIST
#include "card_list.h"
typedef CardList CardContainer;
void loadCardsFromFile(const std::string& filename, CardContainer& container) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    Card card;
    while (file >> card) { // Assuming Card overloads the >> operator
        container.addCard(card);
    }

    file.close();
}
#else
typedef std::set<Card> CardContainer;
void loadCardsFromFile(const std::string& filename, CardContainer& container) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    Card card;
    while (file >> card) { // Assuming Card overloads the >> operator
        container.insert(card);
    }

    file.close();
}
#endif

void playGame(CardContainer& aliceCards, CardContainer& bobCards) {
    // Implement your game logic here for both CardList and std::set
    // For example, finding common cards between aliceCards and bobCards
    std::cout << "Playing the game..." << std::endl;

    // Example logic for demonstration purposes
    // Adjust according to the specific game rules
    for (const auto& card : aliceCards) {
        if (bobCards.find(card) != bobCards.end()) {
            std::cout << "Matching card: " << card << std::endl; // Adjust based on how Card is printed
        }
    }
}

int main() {
    CardContainer aliceCards;
    CardContainer bobCards;

    // Load cards from files
    loadCardsFromFile("alice_cards.txt", aliceCards);
    loadCardsFromFile("bob_cards.txt", bobCards);

    // Play the game
    playGame(aliceCards, bobCards);

    return 0;
}
