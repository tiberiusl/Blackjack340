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
void Card::PrintCardIcon() const {
    int base;
    if (this->getSuit() == "Spade") {
        base = 0x1F0A0;
    } else if (this->getSuit() == "Heart") {
        base = 0x1F0B0;
    } else if (this->getSuit() == "Diamond") {
        base = 0x1F0C0;
    } else if (this->getSuit() == "Clover") {
        base = 0x1F0D0;
    } else {
        cout << "INVALID SUIT";
        return;
    }
    int offset;
    if (this->getVal() >= 1 && this->getVal() <= 10) {
        offset = this->getVal();
    } else if (this->getVal() == 11) {
        offset = 0x0B;
    } else if (this->getVal() == 12) {
        offset = 0x0D;
    } else if (this->getVal() == 13) {
        offset = 0x0E;
    } else {
        cout << "INVALID RANK";
        return;
    }
    int codepoint = base + offset;
    char buffer[5] = {};
    if (codepoint <= 0x7F) {
        buffer[0] = codepoint;
    } else if (codepoint <= 0x7FF) {
        buffer[0] = 0xC0 | ((codepoint >> 6) & 0x1F);
        buffer[1] = 0x80 | (codepoint & 0x3F);
    } else if (codepoint <= 0xFFFF) {
        buffer[0] = 0xE0 | ((codepoint >> 12) & 0x0F);
        buffer[1] = 0x80 | ((codepoint >> 6) & 0x3F);
        buffer[2] = 0x80 | (codepoint & 0x3F);
    } else {
        buffer[0] = 0xF0 | ((codepoint >> 18) & 0x07);
        buffer[1] = 0x80 | ((codepoint >> 12) & 0x3F);
        buffer[2] = 0x80 | ((codepoint >> 6) & 0x3F);
        buffer[3] = 0x80 | (codepoint & 0x3F);
    }
    cout << "Card: " << buffer << endl;
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


