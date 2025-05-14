#include "heart.h"
#include <iostream>

using namespace std;

Heart::Heart() {

    setVal(0);
    this->suit = "Heart";
}

Heart::Heart(int val) {

    setVal(val);
    this->suit = "Heart"; // Default suit
}

Heart::Heart(const Heart& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
    this->suit = "Heart";
}

string Heart::getSuit() const {
    
    return this->suit; 
}

void Heart::printCard() const {
    cout << this->getName() << " of " << this->getSuit() << endl;
}

Card* Heart::clone() const {
    return new Heart(*this);  // uses copy constructor
}