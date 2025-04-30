#include "heart.h"

using namespace std;

Heart::Heart() {

    setVal(0);
    this->suit = "heart"; 
}

Heart::Heart(int val) {

    setVal(val);
    this->suit = "heart"; // Default suit
}

Heart::Heart(const Heart& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
    this->suit = "Heart";
}

string Heart::getSuit() const {
    
    return this->suit; 
}

Card* Heart::clone() const {
    return new Heart(*this);  // uses copy constructor
}