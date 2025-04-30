//implementation file for the card abstract class

#include "card.h"
using namespace std;

Card::Card() {

    this->faceValue = 0;
} 

Card::Card(int val) {

    this->faceValue = val;
}

Card::Card(const Card& toCopy) {
    this->faceValue = toCopy.getVal();
    this->name = toCopy.getName();
}

void Card::setVal(int newVal) {

    this->faceValue = newVal;
}


int Card::getVal() const {

    return this->faceValue;
}

std::string Card::getName() const {
    return this->name;
}        
void Card::setName(const std::string& newName) {
    this->name = newName;
}

/*
The getSuit() and setSuit() methods are pure virtual functions, 
meaning that they must be implemented in any derived class.
This allows for polymorphism, where different types of 
cards can be treated uniformly through the Card interface.
*/

bool operator==(const Card& lhs, const Card& rhs) {
    return lhs.getVal() == rhs.getVal();
}
bool operator<(const Card& lhs, const Card& rhs) {
    return lhs.getVal() < rhs.getVal();
}
bool operator>(const Card& lhs, const Card& rhs) {
    return rhs < lhs;
}


