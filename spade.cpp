#include "spade.h"

using namespace std;

Spade::Spade() {

    setVal(0);
    this->suit = "spade"; // Default suit
}

Spade::Spade(int val) {

    setVal(val);
    this->suit = "spade"; // Default suit
}

string Spade::getSuit() const {
    
    return this->suit; // Return the suit of the card
}