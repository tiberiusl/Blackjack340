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

string Spade::getSuit() const {
    
    return this->suit; 
}

Card* Spade::clone() const {
    return new Spade(*this);  // uses copy constructor
}