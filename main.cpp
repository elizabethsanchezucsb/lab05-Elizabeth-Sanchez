// Feb 14: This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
// main.cpp
// This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"

using namespace std;

void loadCards(const string& filename, CardList& cards) {
    ifstream file(filename);
    string suit;
    int value;

    while (file >> suit >> value) {
        cards.insert(Card(suit, value));
    }

    file.close();
}

void printCards(const CardList& cards) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        cout << *it << endl;
    }
}

void playGame(CardList& aliceCards, CardList& bobCards) {
    cout << "Alice's cards:" << endl;
    printCards(aliceCards);

    cout << "Bob's cards:" << endl;
    printCards(bobCards);

    cout << "Alice plays:" << endl;
    for (auto it = aliceCards.begin(); it != aliceCards.end(); ++it) {
        cout << *it << endl;
        bobCards.remove(*it);
    }

    cout << "Bob plays:" << endl;
    for (auto it = bobCards.rbegin(); it != bobCards.rend(); ++it) {
        cout << *it << endl;
        aliceCards.remove(*it);
    }

    cout << "Game over!" << endl;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    CardList aliceCards;
    CardList bobCards;

    loadCards(argv[1], aliceCards);
    loadCards(argv[2], bobCards);

    playGame(aliceCards, bobCards);

    return 0;
}
