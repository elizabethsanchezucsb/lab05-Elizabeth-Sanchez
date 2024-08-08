#include "card_list.h"
#include "card.h"
#include <cassert>
#include <iostream>

void testCardComparison() {
    Card card1(Card::CLUBS, 1);   // Ace of Clubs
    Card card2(Card::DIAMONDS, 11); // Jack of Diamonds
    Card card3(Card::CLUBS, 1);   // Ace of Clubs

    assert(card1 == card3);
    assert(card1 != card2);
    assert(card1 < card2);
    assert(card2 > card1);

    std::cout << "Card comparison tests passed." << std::endl;
}

void testCardListInsertAndFind() {
    CardList cardList;

    Card card1(Card::CLUBS, 1);   // Ace of Clubs
    Card card2(Card::DIAMONDS, 11); // Jack of Diamonds
    Card card3(Card::SPADES, 5);  // 5 of Spades
    Card card4(Card::HEARTS, 13); // King of Hearts

    cardList.insert(card1);
    cardList.insert(card2);
    cardList.insert(card3);
    cardList.insert(card4);

    assert(cardList.find(card1));
    assert(cardList.find(card2));
    assert(cardList.find(card3));
    assert(cardList.find(card4));

    std::cout << "Card list insert and find tests passed." << std::endl;
}

void testCardListPrintInOrder() {
    CardList cardList;

    Card card1(Card::CLUBS, 1);   // Ace of Clubs
    Card card2(Card::DIAMONDS, 11); // Jack of Diamonds
    Card card3(Card::SPADES, 5);  // 5 of Spades
    Card card4(Card::HEARTS, 13); // King of Hearts

    cardList.insert(card1);
    cardList.insert(card2);
    cardList.insert(card3);
    cardList.insert(card4);

    std::cout << "Printing card list in order:" << std::endl;
    cardList.printInOrder();  // Should print in sorted order
}

void testCardListEmpty() {
    CardList cardList;
    Card card1(Card::CLUBS, 1);

    assert(!cardList.find(card1));

    std::cout << "Empty card list tests passed." << std::endl;
}

int main() {
    testCardComparison();
    testCardListInsertAndFind();
    testCardListPrintInOrder();
    testCardListEmpty();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
