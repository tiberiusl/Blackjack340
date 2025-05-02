#include "participant.h"
#include <iostream>

using namespace std;

Participant::Participant() {
    this->hand = new LinkedList;
}

Participant::~Participant() {
    // Destructor implementation
    this->hand->clear(); // Clear the hand when the participant is destroyed
}

void Participant::addCard(Card* card) {

    this->hand->push_back(card); // Add a card to the hand
}

void Participant::showCards() const {
    cout << "Showing cards in hand: " << endl;

    //exit early if hand is empty
    if (this->hand->size() == 0) {
        cout << "No cards in hand!" << endl;
        return;
    }

    //traverse through linkedlist
    //calling printCard on each Card* in list
    Node* current = this->hand->getHead();
    while (current) {
        Card* currentCard = current->getData();
        currentCard->printCard();
        current = current->getNext();
    }
}

int Participant::calculateHandValue() const {

//to implement
    return 1;
}

