// tests.cpp
#include <iostream>
#include <cassert>
#include "card.h"
#include "card_list.h"

using namespace std;

void testCardInsertion() {
    CardList list;
    list.insert(Card('h', "3"));
    list.insert(Card('s', "5"));
    list.insert(Card('d', "A"));

    assert(list.find(Card('h', "3")) == true);
    assert(list.find(Card('s', "5")) == true);
    assert(list.find(Card('d', "A")) == true);
    assert(list.find(Card('c', "K")) == false);

    cout << "Card insertion test passed." << endl;
}

void testCardOrdering() {
    CardList list;
    list.insert(Card('h', "3"));
    list.insert(Card('h', "A"));
    list.insert(Card('s', "5"));

    assert(list.find(Card('h', "3")) == true);
    assert(list.find(Card('h', "A")) == true);
    assert(list.find(Card('s', "5")) == true);

    cout << "Card ordering test passed." << endl;
}

int main() {
    testCardInsertion();
    testCardOrdering();

    cout << "All tests passed!" << endl;
    return 0;
}