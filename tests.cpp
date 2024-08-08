#include <iostream>
#include <cassert>
#include "card.h"
#include "card_list.h"

void testCardClass() {
    Card c1('H', 10);
    Card c2('S', 5);
    Card c3('H', 10);

    assert(c1.getSuit() == 'H');
    assert(c1.getValue() == 10);
    assert(c1.toString() == "10H");

    assert(c2 < c1);
    assert(c1 == c3);
    assert(!(c1 < c3) && !(c3 < c1));

    std::cout << "Card class tests passed." << std::endl;
}

void testCardListInsert() {
    CardList list;
    list.insert(Card('H', 5));
    list.insert(Card('S', 10));
    list.insert(Card('D', 3));

    assert(list.contains(Card('H', 5)));
    assert(list.contains(Card('S', 10)));
    assert(list.contains(Card('D', 3)));
    assert(!list.contains(Card('C', 7)));

    std::cout << "CardList insert tests passed." << std::endl;
}

void testCardListRemove() {
    CardList list;
    list.insert(Card('H', 5));
    list.insert(Card('S', 10));
    list.insert(Card('D', 3));

    list.remove(Card('S', 10));
    assert(!list.contains(Card('S', 10)));
    assert(list.contains(Card('H', 5)));
    assert(list.contains(Card('D', 3)));

    std::cout << "CardList remove tests passed." << std::endl;
}

void testCardListSuccessor() {
    CardList list;
    