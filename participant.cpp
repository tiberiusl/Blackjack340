#include "participant.h"
#include <iostream>

using namespace std;

Participant::Participant() {
    // Constructor implementation
}

Participant::~Participant() {
    // Destructor implementation
    clearHand(); // Clear the hand when the participant is destroyed
}

void Participant::addCard(Card* card) {

    this->hand.push_back(card); // Add a card to the hand
}

void Participant::showCards() const {

    // Show all cards in hand
    cout << "Cards in hand: " << endl;
    for (int i = 0; i < this->hand.size(); i++) {
        cout << this->hand[i]->getVal() << " of " << this->hand[i]->getSuit() << endl;
    }
}

void Participant::clearHand() {

//to implement

}

int Participant::calculateHandValue() const {

//to implement

}

