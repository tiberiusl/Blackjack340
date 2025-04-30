#include "spade.h"

using namespace std;

Spade::Spade() {

    setVal(0);
    this->suit = "Spade"; // Default suit
}

Spade::Spade(int val) {

    setVal(val);
    this->suit = "Spade"; // Default suit
}

Spade::Spade(const Spade& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
    this->suit = "Spade";
}

string Spade::getSuit() const {
    
    return this->suit; // Return the suit of the card
}

Card* Spade::clone() const {
    return new Spade(*this);  // uses copy constructor
}