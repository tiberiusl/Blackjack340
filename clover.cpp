#include "clover.h"

using namespace std;

Clover::Clover() {

    setVal(0);
    this->suit = "clover"; // Default suit
}

Clover::Clover(int val) {

    setVal(val);
    this->suit = "clover"; // Default suit
}

string Clover::getSuit() const {

    return this->suit; // Return the suit of the card
}