#include "deck.h"


Deck::Deck() {

//to implement
    // Initialize the deck with 52 cards (13 ranks * 4 suits)
    for (int i = 1; i <= 13; ++i) {
        cardDeck.push_back(new Diamond(i));
        cardDeck.push_back(new Heart(i));
        cardDeck.push_back(new Spade(i));
        cardDeck.push_back(new Clover(i));
    }
}

Deck::~Deck() {

//to implement    
}

void Deck::takeTurn() {

    this->shuffle();    
}

void Deck::shuffle() {

//to implement    
}

Card* Deck::pop_back() {

//to implement
}

int Deck::size() const {

    return this->size(); 
}