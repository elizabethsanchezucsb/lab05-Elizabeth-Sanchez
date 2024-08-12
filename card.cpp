#include "card.h"
#include <map>

bool Card::operator<(const Card& other) const {
    if (suit != other.suit) {
        return getSuitValue() < other.getSuitValue();
    }
    return getRankValue() < other.getRankValue();
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && rank == other.rank;
}

int Card::getSuitValue() const {
    std::map<char, int> suitOrder = {{'c', 0}, {'d', 1}, {'s', 2}, {'h', 3}};
    return suitOrder[suit];
}

int Card::getRankValue() const {
    std::map<std::string, int> rankOrder = {
        {"a", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
        {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
        {"j", 11}, {"q", 12}, {"k", 13}
    };
    return rankOrder[rank];
}