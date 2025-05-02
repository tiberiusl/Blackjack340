#include "clover.h"
#include <iostream>


using namespace std;

Clover::Clover() {

    setVal(0);
    this->suit = "Clover"; 
}

Clover::Clover(int val) {

    setVal(val);
    this->suit = "Clover"; 
}

Clover::Clover(const Clover& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
    this->suit = "Clover";
}

string Clover::getSuit() const {

    return this->suit; // Return the suit of the card
}

void Clover::printCard() const {
    cout << this->getName() << " of " << this->getSuit() << endl;
}

Card* Clover::clone() const {
    return new Clover(*this);  // uses copy constructor
}