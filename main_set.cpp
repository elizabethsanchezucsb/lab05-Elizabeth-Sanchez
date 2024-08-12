#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "card.h"

enum class GameState {
    ALICE_TURN,
    BOB_TURN,
    GAME_OVER
};

void readCardsFromFile(const std::string& filename, std::set<Card>& cards) {
    std::ifstream file(filename);
    char suitChar;
    std::string rankStr;
    while (file >> suitChar >> rankStr) {
        Card::Suit suit;
        Card::Rank rank;

        switch (suitChar) {
            case 'c': suit = Card::Suit::CLUBS; break;
            case 'd': suit = Card::Suit::DIAMONDS; break;
            case 's': suit = Card::Suit::SPADES; break;
            case 'h': suit = Card::Suit::HEARTS; break;
            default: continue; // Invalid suit
        }

        if (rankStr == "a") rank = Card::Rank::ACE;
        else if (rankStr == "j") rank = Card::Rank::JACK;
        else if (rankStr == "q") rank = Card::Rank::QUEEN;
        else if (rankStr == "k") rank = Card::Rank::KING;
        else {
            try {
                int rankNum = std::stoi(rankStr);
                if (rankNum >= 2 && rankNum <= 10) {
                    rank = static_cast<Card::Rank>(rankNum);
                } else {
                    continue; // Invalid rank
                }
            } catch (std::invalid_argument&) {
                continue; // Invalid rank
            }
        }

        cards.insert(Card(suit, rank));
    }
}

void printCards(const std::set<Card>& cards) {
    for (const auto& card : cards) {
        std::cout << card << std::endl;
    }
}

bool findAndRemoveMatch(std::set<Card>& playerCards, std::set<Card>& opponentCards, const std::string& playerName) {
    for (auto it = playerCards.begin(); it != playerCards.end(); ++it) {
        if (opponentCards.find(*it) != opponentCards.end()) {
            std::cout << playerName << " picked matching card " << *it << std::endl;
            opponentCards.erase(*it);
            playerCards.erase(it);
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <alice_cards_file> <bob_cards_file>" << std::endl;
        return 1;
    }

    std::set<Card> aliceCards, bobCards;
    readCardsFromFile(argv[1], aliceCards);
    readCardsFromFile(argv[2], bobCards);

    GameState currentState = GameState::ALICE_TURN;

    while (currentState != GameState::GAME_OVER) {
        switch (currentState) {
            case GameState::ALICE_TURN:
                if (findAndRemoveMatch(aliceCards, bobCards, "Alice")) {
                    currentState = GameState::ALICE_TURN;
                } else {
                    currentState = GameState::BOB_TURN;
                }
                break;

            case GameState::BOB_TURN:
                if (findAndRemoveMatch(bobCards, aliceCards, "Bob")) {
                    currentState = GameState::BOB_TURN;
                } else {
                    currentState = GameState::GAME_OVER;
                }
                break;

            default:
                currentState = GameState::GAME_OVER;
                break;
        }
    }

    std::cout << "\nAlice's cards:" << std::endl;
    printCards(aliceCards);

    std::cout << "\nBob's cards:" << std::endl;
    printCards(bobCards);

    return 0;
}