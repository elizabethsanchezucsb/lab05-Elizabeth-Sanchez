#include <iostream>
#include <cassert>
#include "card.h"
#include "card_list.h"

void testInsert() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.contains(Card("c", "a")));
    assert(cl.contains(Card("d", "2")));
    assert(cl.contains(Card("h", "k")));
    assert(cl.contains(Card("s", "5")));

    std::cout << "testInsert passed." << std::endl;
}

void testDelete() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    cl.remove(Card("d", "2"));
    assert(!cl.contains(Card("d", "2")));

    cl.remove(Card("h", "k"));
    assert(!cl.contains(Card("h", "k")));

    std::cout << "testDelete passed." << std::endl;
}

void testFind() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.contains(Card("c", "a")));
    assert(cl.contains(Card("d", "2")));
    assert(cl.contains(Card("h", "k")));
    assert(cl.contains(Card("s", "5")));
    assert(!cl.contains(Card("d", "3")));

    std::cout << "testFind passed." << std::endl;
}

void testSuccessor() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.successor(Card("c", "a")) == Card("d", "2"));
    assert(cl.successor(Card("d", "2")) == Card("s", "5"));
    assert(cl.successor(Card("s", "5")) == Card("h", "k"));
    assert(cl.successor(Card("h", "k")).suit == "" && cl.successor(Card("h", "k")).value == "");

    std::cout << "testSuccessor passed." << std::endl;
}

void testPredecessor() {
    CardList cl;
    cl.insert(Card("c", "a"));
    cl.insert(Card("d", "2"));
    cl.insert(Card("h", "k"));
    cl.insert(Card("s", "5"));

    assert(cl.predecessor(Card("h", "k")) == Card("s", "5"));
    assert(cl.predecessor(Card("s", "5")) == Card("d", "2"));
    assert(cl.predecessor(Card("d", "2")) == Card("c", "a"));
    assert(cl.predecessor(Card("c", "a")).suit == "" && cl.predecessor(Card("c", "a")).value == "");

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
