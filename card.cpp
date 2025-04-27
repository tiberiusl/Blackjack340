//implementation file for the card abstract class

#include "card.h"
using namespace std;

Card::Card() {

    this->faceValue = 0;
} 

Card::Card(int val) {

    this->faceValue = val;
}

void Card::setVal(int newVal) {

    this->faceValue = newVal;
}


int Card::getVal() const {

    return this->faceValue;
}

/*
The getSuit() and setSuit() methods are pure virtual functions, 
meaning that they must be implemented in any derived class.
This allows for polymorphism, where different types of 
cards can be treated uniformly through the Card interface.
*/


