#include "spade.h"

using namespace std;

Spade::Spade() {

    setVal(0);
    this->suit = "spade"; 
}

Spade::Spade(int val) {

    setVal(val);
    this->suit = "spade"; 
}

string Spade::getSuit() const {
    
    return this->suit; 
}

void Spade::setSuit(const string& newSuit) {
    
    this->suit = newSuit; 
}