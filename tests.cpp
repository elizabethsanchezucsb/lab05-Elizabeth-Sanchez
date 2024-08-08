#include <iostream>
#include "card_list.h"

void test_bst() {
    CardBST bst;

    bst.insert(Card(CLUBS, 3));
    bst.insert(Card(SPADES, 10));
    bst.insert(Card(HEARTS, 7));
    bst.insert(Card(DIAMONDS, 5));

    std::cout << "Testing BST operations:\n";
    std::cout << "Find CLUBS 3: " << bst.find(Card(CLUBS, 3)) << "\n";
    std::cout << "Find DIAMONDS 10: " << bst.find(Card(DIAMONDS, 10)) << "\n";
    std::cout << "Find SPADES 10: " << bst.find(Card(SPADES, 10)) << "\n";
    std::cout << "Find HEARTS 5: " << bst.find(Card(HEARTS, 5)) << "\n";

    std::cout << "Inorder traversal:\n";
    bst.print_inorder();
}

int main() {
    test_bst();
    return 0;
}
