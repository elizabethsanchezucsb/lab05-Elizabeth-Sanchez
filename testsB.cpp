#include <iostream>
#include <cassert>
#include "card.h"
#include "card_list.h"

void testInsert() {
    CardList cl;
    cl.insert(Card(1, 'c'));
    cl.insert(Card(2, 'd'));
    cl.insert(Card(13, 'h'));
    cl.insert(Card(5, 's'));

    assert(cl.contains(Card(1, 'c')));
    assert(cl.contains(Card(2, 'd')));
    assert(cl.contains(Card(13, 'h')));
    assert(cl.contains(Card(5, 's')));

    std::cout << "testInsert passed." << std::endl;
}

void testDelete() {
    CardList cl;
    cl.insert(Card(1, 'c'));
    cl.insert(Card(2, 'd'));
    cl.insert(Card(13, 'h'));
    cl.insert(Card(5, 's'));

    cl.remove(Card(2, 'd'));
    assert(!cl.contains(Card(2, 'd')));

    cl.remove(Card(13, 'h'));
    assert(!cl.contains(Card(13, 'h')));

    std::cout << "testDelete passed." << std::endl;
}

void testFind() {
    CardList cl;
    cl.insert(Card(1, 'c'));
    cl.insert(Card(2, 'd'));
    cl.insert(Card(13, 'h'));
    cl.insert(Card(5, 's'));

    assert(cl.contains(Card(1, 'c')));
    assert(cl.contains(Card(2, 'd')));
    assert(cl.contains(Card(13, 'h')));
    assert(cl.contains(Card(5, 's')));
    assert(!cl.contains(Card(3, 'd')));

    std::cout << "testFind passed." << std::endl;
}

void testSuccessor() {
    CardList cl;
    cl.insert(Card(1, 'c'));
    cl.insert(Card(2, 'd'));
    cl.insert(Card(13, 'h'));
    cl.insert(Card(5, 's'));

    assert(*cl.successor(Card(1, 'c')) == Card(2, 'd'));
    assert(*cl.successor(Card(2, 'd')) == Card(5, 's'));
    assert(*cl.successor(Card(5, 's')) == Card(13, 'h'));
    assert(cl.successor(Card(13, 'h')) == nullptr);

    std::cout << "testSuccessor passed." << std::endl;
}

void testPredecessor() {
    CardList cl;
    cl.insert(Card(1, 'c'));
    cl.insert(Card(2, 'd'));
    cl.insert(Card(13, 'h'));
    cl.insert(Card(5, 's'));

    assert(*cl.predecessor(Card(13, 'h')) == Card(5, 's'));
    assert(*cl.predecessor(Card(5, 's')) == Card(2, 'd'));
    assert(*cl.predecessor(Card(2, 'd')) == Card(1, 'c'));
    assert(cl.predecessor(Card(1, 'c')) == nullptr);

    std::cout << "testPredecessor passed." << std::endl;
}

int main() {
    testInsert();
    testDelete();
    testFind();
    testSuccessor();
    testPredecessor();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}