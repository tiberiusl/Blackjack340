#include "diamond.h"
#include <iostream>
#include <string>
using namespace std;

Diamond::Diamond() {

    setVal(0);
    this->suit = "Diamond"; // Default suit
}

Diamond::Diamond(int val) {

    setVal(val);
    this->suit = "Diamond"; // Default suit
}

string Diamond::getSuit() const {
    
    return this->suit; // Return the suit of the card
}