#include "heart.h"

using namespace std;

Heart::Heart() {

    setVal(0);
    this->suit = "heart"; 
}

Heart::Heart(int val) {

    setVal(val);
    this->suit = "heart"; 
}

string Heart::getSuit() const {
    
    return this->suit; 
}

void Heart::setSuit(const string& newSuit) {
    
    this->suit = newSuit; 
}