#include "diamond.h"
#include <iostream>


using namespace std;

Diamond::Diamond() {

    setVal(0);
    this->suit = "Diamond"; 
}

Diamond::Diamond(int val) {

    setVal(val);
    this->suit = "Diamond"; 
}

Diamond::Diamond(const Diamond& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
    this->suit = "Diamond";
}

string Diamond::getSuit() const {

    return this->suit; // Return the suit of the card
}

void Diamond::printCard() const {
    cout << this->getName() << " of " << this->getSuit() << endl;
}

Card* Diamond::clone() const {
    return new Diamond(*this);  // uses copy constructor
}