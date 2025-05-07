#include "dealer.h"
/*
Dealer::Dealer() {
    this->hand = new LinkedList;
    //to implement
}

Dealer::~Dealer() {
    this->hand->clear();
//to implement
}
*/
void Dealer::takeTurn(Deck& myDeck) {
    int handVal = this->calculateHandValue();
    while (handVal < 18) { //hit until 17 or over
        this->addCard(myDeck.pop_back());
        handVal = this->calculateHandValue();
    }
//to implement
}