#include <iostream>
#include <cassert>
#include "card_list.h"
#include "card.h"

// Test helper function to verify card list contents
void verifyCardList(CardList& cardList, const std::vector<Card>& expectedCards) {
    std::vector<Card> actualCards;
    cardList.inOrderTraversal([&](const Card& card) {
        actualCards.push_back(card);
    });

    assert(actualCards.size() == expectedCards.size() && "Card list sizes do not match!");

    for (size_t i = 0; i < expectedCards.size(); ++i) {
        assert(actualCards[i] == expectedCards[i] && "Card lists do not match!");
    }
}

void testCardList() {
    CardList cardList;
    cardList.addCard(Card("c", "2"));
    cardList.addCard(Card("d", "3"));
    cardList.addCard(Card("s", "4"));
    cardList.addCard(Card("h", "5"));

    std::vector<Card> expectedCards = {
        Card("c", "2"),
        Card("d", "3"),
        Card("h", "5"),
        Card("s", "4")
    };

    verifyCardList(cardList, expectedCards);

    std::cout << "CardList test passed!" << std::endl;
}

void testCardComparison() {
    Card card1("c", "2");
    Card card2("c", "2");
    Card card3("d", "3");

    assert(card1 == card2 && "Card equality test failed!");
    assert(!(card1 == card3) && "Card inequality test failed!");

    std::cout << "Card comparison test passed!" << std::endl;
}

int main() {
    testCardList();
    testCardComparison();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
