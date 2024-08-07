#include "card.h"
#include "card_list.h"
#include <iostream>
#include <cassert>

using namespace std;

void testInsert() {
    CardList cardList;
    cardList.insert(Card("hearts", 10));
    cardList.insert(Card("clubs", 2));
    cardList.insert(Card("diamonds", 5));

    // Test if cards are inserted correctly
    assert(cardList.find(Card("hearts", 10)) != nullptr);
    assert(cardList.find(Card("clubs", 2)) != nullptr);
    assert(cardList.find(Card("diamonds", 5)) != nullptr);
    cout << "testInsert passed" << endl;
}
void testFind() {
    CardList cardList;
    cardList.insert(Card("hearts", 10));
    cardList.insert(Card("clubs", 2));
    cardList.insert(Card("diamonds", 5));

    // Test if find works correctly
    assert(cardList.find(Card("hearts", 10)) != nullptr);
    assert(cardList.find(Card("spades", 7)) == nullptr);
    cout << "testFind passed" << endl;
}

void testDelete() {
    CardList cardList;
    cardList.insert(Card("hearts", 10));
    cardList.insert(Card("clubs", 2));
    cardList.insert(Card("diamonds", 5));
    cardList.remove(Card("clubs", 2));

    // Test if delete works correctly
    assert(cardList.find(Card("clubs", 2)) == nullptr);
    cout << "testDelete passed" << endl;
}

void testSuccessor() {
    CardList cardList;
    cardList.insert(Card("hearts", 10));
    cardList.insert(Card("clubs", 2));
    cardList.insert(Card("diamonds", 5));

    // Test if successor works correctly
    assert(cardList.successor(Card("clubs", 2))->value == 5);
    cout << "testSuccessor passed" << endl;
}

void testPredecessor() {
    CardList cardList;
    cardList.insert(Card("hearts", 10));
    cardList.insert(Card("clubs", 2));
    cardList.insert(Card("diamonds", 5));

    // Test if predecessor works correctly
    assert(cardList.predecessor(Card("diamonds", 5))->value == 2);
    cout << "testPredecessor passed" << endl;
}

int main() {
    testInsert();
    testFind();
    testDelete();
    testSuccessor();
    testPredecessor();
    cout << "All tests passed!" << endl;
    return 0;
}

