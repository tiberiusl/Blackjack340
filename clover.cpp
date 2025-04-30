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

Clover::Clover(const Clover& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
    this->suit = "Clover";
}

string Clover::getSuit() const {

    return this->suit; // Return the suit of the card
}

Card* Clover::clone() const {
    return new Clover(*this);  // uses copy constructor
}