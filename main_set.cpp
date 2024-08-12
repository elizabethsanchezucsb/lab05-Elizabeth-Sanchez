#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "card.h"

using namespace std;

// Convert suit and value from strings to enum types
Card::Suit stringToSuit(const string& s) {
    if (s == "c") return Card::Clubs;
    if (s == "d") return Card::Diamonds;
    if (s == "h") return Card::Hearts;
    if (s == "s") return Card::Spades;
    throw invalid_argument("Invalid suit");
}

Card::Value stringToValue(const string& v) {
    if (v == "a") return Card::Ace;
    if (v == "2") return Card::Two;
    if (v == "3") return Card::Three;
    if (v == "4") return Card::Four;
    if (v == "5") return Card::Five;
    if (v == "6") return Card::Six;
    if (v == "7") return Card::Seven;
    if (v == "8") return Card::Eight;
    if (v == "9") return Card::Nine;
    if (v == "10") return Card::Ten;
    if (v == "j") return Card::Jack;
    if (v == "q") return Card::Queen;
    if (v == "k") return Card::King;
    throw invalid_argument("Invalid value");
}

// Read a card from the file
Card readCard(ifstream& file) {
    string suitStr, valueStr;
    file >> suitStr >> valueStr;
    return Card(stringToSuit(suitStr), stringToValue(valueStr));
}

// Print the cards
void printCards(const set<Card>& cards) {
    for (const auto& card : cards) {
        char suitChar;
        switch (card.getSuit()) {
            case Card::Clubs: suitChar = 'c'; break;
            case Card::Diamonds: suitChar = 'd'; break;
            case Card::Hearts: suitChar = 'h'; break;
            case Card::Spades: suitChar = 's'; break;
        }
        string valueStr;
        switch (card.getValue()) {
            case Card::Ace: valueStr = "a"; break;
            case Card::Two: valueStr = "2"; break;
            case Card::Three: valueStr = "3"; break;
            case Card::Four: valueStr = "4"; break;
            case Card::Five: valueStr = "5"; break;
            case Card::Six: valueStr = "6"; break;
            case Card::Seven: valueStr = "7"; break;
            case Card::Eight: valueStr = "8"; break;
            case Card::Nine: valueStr = "9"; break;
            case Card::Ten: valueStr = "10"; break;
            case Card::Jack: valueStr = "j"; break;
            case Card::Queen: valueStr = "q"; break;
            case Card::King: valueStr = "k"; break;
        }
        cout << suitChar << " " << valueStr << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " alice_file bob_file" << endl;
        return 1;
    }

    ifstream aliceFile(argv[1]);
    ifstream bobFile(argv[2]);

    if (!aliceFile || !bobFile) {
        cerr << "Error opening files" << endl;
        return 1;
    }

    set<Card> aliceHand;
    set<Card> bobHand;

    // Read cards from files
    while (aliceFile.peek() != EOF) {
        aliceHand.insert(readCard(aliceFile));
    }

    while (bobFile.peek() != EOF) {
        bobHand.insert(readCard(bobFile));
    }

    // Game logic: Matching and removing cards
    bool aliceTurn = true;
    while (!aliceHand.empty() && !bobHand.empty()) {
        if (aliceTurn) {
            auto it = aliceHand.begin();
            auto match = bobHand.find(*it);
            if (match != bobHand.end()) {
                cout << "Alice picked matching card " << (char)(it->getSuit() + 'c') << " " << (it->getValue() + 1) << endl;
                bobHand.erase(match);
                aliceHand.erase(it);
            } else {
                break; // No more matches
            }
        } else {
            auto it = bobHand.rbegin();
            auto match = aliceHand.find(*it);
            if (match != aliceHand.end()) {
                cout << "Bob picked matching card " << (char)(it->getSuit() + 'c') << " " << (it->getValue() + 1) << endl;
                aliceHand.erase(match);
                bobHand.erase(it.base());
            } else {
                break; // No more matches
            }
        }
        aliceTurn = !aliceTurn;
    }

    // Print remaining cards
    cout << "\nAlice's cards:" << endl;
    printCards(aliceHand);
    cout << "Bob's cards:" << endl;
    printCards(bobHand);

    return 0;
}
