//implementation file for the card abstract class

#include "card.h"
#include <iostream>
using namespace std;

Card::Card() {

    this->faceValue = 0;
    this->name = "";
} 

Card::Card(int val) {

    this->faceValue = val;
    this->name = "";
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

// for klondike
bool Card::getFaceDown() const {
    return this->facedown;
}
void Card::setFaceDown(bool newFaceDown) {
    this->facedown = newFaceDown;
}
void Card::DisplayCard() const {
    if (this->getFaceDown() == true) {
        cout << GREY << "??" << RESET;
        return;
    }
    if (this->getSuit() == "Spade") {
        cout << WHITE << "S";
    } else if (this->getSuit() == "Diamond") {
        cout << RED << "H";
    } else if (this->getSuit() == "Heart") {
        cout << RED << "D";
    } else if (this->getSuit() == "Clover") {
        cout << WHITE << "C";
    } else {
        cout << "X";
    }
    if (this->getVal() <= 10) {
        cout << this->getVal();
    } else if (this->getVal() == 11) {
        cout << "J";
    } else if (this->getVal() == 12) {
        cout << "Q";
    } else if (this->getVal() == 13) {
        cout << "K";
    } else {
        cout << "X";
    }
    cout << RESET;
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


