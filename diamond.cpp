#include "diamond.h"

using namespace std;

Diamond::Diamond() {

    setVal(0);
    this->suit = "Diamond"; 
}

Diamond::Diamond(int val) {

    setVal(val);
    this->suit = "Diamond"; 
}

string Diamond::getSuit() const {

    return this->suit; 
}

void Diamond::setSuit(const string& newSuit) {

    this->suit = newSuit; 
}