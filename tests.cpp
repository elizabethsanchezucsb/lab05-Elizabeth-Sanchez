
#include "card.h"
#include "card_list.h"
#include <iostream>

void testInsertAndFind() {
    CardList list;
    Card card1('h', '5');
    Card card2('s', 'k');
    Card card3('d', 'a');

    list.insert(card1);
    list.insert(card2);
    list.insert(card3);

    std::cout << "Test Insert and Find: ";
    if (list.find(card1) && list.find(card2) && list.find(card3)) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

void testRemove() {
    CardList list;
    Card card1('h', '5');
    Card card2('s', 'k');
    Card card3('d', 'a');

    list.insert(card1);
    list.insert(card2);
    list.insert(card3);

    list.remove(card2);

    std::cout << "Test Remove: ";
    if (list.find(card1) && !list.find(card2) && list.find(card3)) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

void testSuccessorAndPredecessor() {
    CardList list;
    Card card1('h', '5');
    Card card2('s', 'k');
    Card card3('d', 'a');

    list.insert(card1);
    list.insert(card2);
    list.insert(card3);

    std::cout << "Test Successor and Predecessor: ";
    Card* successor = list.successor(card1);
    Card* predecessor = list.predecessor(card2);

    if (successor && *successor == card2 && predecessor && *predecessor == card1) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

int main() {
    testInsertAndFind();
    testRemove();
    testSuccessorAndPredecessor();
    return 0;
}