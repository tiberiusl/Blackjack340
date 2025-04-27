#include "card.h"
using namespace std;

Card::Card() {

    this->value = 0;
    this->rank = "Unknown";
} 

Card::Card(int val) {

    this->value = val;
    if (val == 1) {
        this->rank = "Ace";
    } else if (val >= 2 && val <= 10) {
        this->rank = to_string(val);;
    } else if (val == 11) {
        this->rank = "Jack";
    } else if (val == 12) {
        this->rank = "Queen";
    } else if (val == 13) {
        this->rank = "King";
    } else {
        this->rank = "Unknown";
    }
}

void Card::setVal(int newVal) {
    this->value = newVal;
}

void Card::setRank(const string& newRank) {
    this->rank = newRank;
}

int Card::getVal() const {
    return this->value;
}

string Card::getRank() const {
    return this->rank;
}

/*
The getSuit() and setSuit() methods are pure virtual functions, 
meaning that they must be implemented in any derived class.
The printCard() method is also a pure virtual function, 
which means that it must be implemented in any derived class 
as well. This allows for polymorphism, where different types of 
cards can be treated uniformly through the Card interface.
*/


