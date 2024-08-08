#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"

void playGame(CardList& player1, CardList& player2) {
    while (true) {
        Card p1Card = player1.successor(Card('A', 0));  // Get the smallest card
        Card p2Card = player2.successor(Card('A', 0));

        std::cout << "Alice plays " << p1Card.toString() << ". Bob plays " << p2Card.toString() << ". ";

        player1.remove(p1Card);
        player2.remove(p2Card);

        if (p1Card.getValue() > p2Card.getValue()) {
            std::cout << "Alice wins the round." << std::endl;
            player1.insert(p1Card);
            player1.insert(p2Card);
        } else if (p2Card.getValue() > p1Card.getValue()) {
            std::cout << "Bob wins the round." << std::endl;
            player2.insert(p1Card);
            player2.insert(p2Card);
        } else {
            std::cout << "Tie. Cards discarded." << std::endl;
        }

        // Check if either player has run out of cards
        if (!player1.contains(player1.successor(Card('A', 0)))) {
            if (!player2.contains(player2.successor(Card('A', 0)))) {
                std::cout << "Tie game!" << std::endl;
            } else {
                std::cout << "Bob wins!" << std::endl;
            }
            break;
        } else if (!player2.contains(player2.successor(Card('A', 0)))) {
            std::cout << "Alice wins!" << std::endl;
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <player1_file> <player2_file>" << std::endl;
        return 1;
    }

    CardList player1, player2;
    std::ifstream file1(argv[1]), file2(argv[2]);

    if (!file1 || !file2) {
        std::cerr << "Error opening input files." << std::endl;
        return 1;
    }

    char suit;
    int value;

    while (file1 >> value >> suit) {
        player1.insert(Card(suit, value));
    }

    while (file2 >> value >> suit) {
        player2.insert(Card(suit, value));
    }

    playGame(player1, player2);

    return 0;
}