#include "participant.h"
#include <iostream>

using namespace std;

Participant::Participant() {
    this->hand = new LinkedList;
}

Participant::~Participant() {
    
    this->hand->clear();   // clear all nodes/cards
    delete this->hand;     // free the LinkedList object itself
    this->hand = nullptr;  // avoid dangling pointer
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
    //traverse through list
    //sum the int value of all Card*
    //if ace encountered, increment numAces
    //if total value > 21, decrement by 10
    //until total value < 21 or numAces = 0

    int handValue = 0;
    int numAces = 0;
    
    //if hand empty, return 0
    if (this->hand->size() == 0) {
        return handValue;
    }

    //start traversal
    Node* current = this->hand->getHead();
    while (current) {
        //add Card* value to handValue
        Card* currentCard = current->getData();
        handValue += currentCard->getVal();
        //count aces
        if (currentCard->getName() == "Ace") {
            ++numAces;
        }
        current = current->getNext();
    }

    while (handValue > 21 && numAces > 0) {
        handValue -= 10;
        --numAces;
    }
    return handValue;
}

LinkedList* Participant::getHand() const {
    return this->hand;
}

