#include "heart.h"

using namespace std;

Heart::Heart() {

    setVal(0);
    this->suit = "heart"; // Default suit
}

Heart::Heart(int val) {

    setVal(val);
    this->suit = "heart"; // Default suit
}

string Heart::getSuit() const {
    
    return this->suit; // Return the suit of the card
}