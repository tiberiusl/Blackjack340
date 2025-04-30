#include "clover.h"

using namespace std;

Clover::Clover() {

    setVal(0);
    this->suit = "clover"; 
}

Clover::Clover(int val) {

    setVal(val);
    this->suit = "clover"; 
}

string Clover::getSuit() const {

    return this->suit; 
}

void Clover::setSuit(const string& newSuit) {

    this->suit = newSuit; 
}