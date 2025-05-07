#include "blackjack.h"
#include <iostream>

using namespace std;

BlackJack::BlackJack() {
    this->player = Player();
    this->dealer = Dealer();
    this->deck = Deck();
//to implement    
}

BlackJack::~BlackJack() {

//to implement    
}

void BlackJack::playGame() {
    this->player.takeTurn(this->deck);
    this->dealer.takeTurn(this->deck);
//to implement    
}

void BlackJack::startGame() {
    this->deck.fill(); //fill deck
    //shuffle deck

    for (unsigned int i = 0; i < 2; ++i) { //add two cards to dealer + player
        this->player.addCard(this->deck.pop_back());
        this->dealer.addCard(this->deck.pop_back());
    }

//to implement    
}

void BlackJack::endGame() {

//to implement        
}
