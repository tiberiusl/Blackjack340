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
    //initialize player, dealer, and deck
    this->startGame();
    bool win; //shows if player wins or loses

    //player(s) and dealer take their turns
    this->player.takeTurn(this->deck);
    this->dealer.takeTurn(this->deck);

    //display final hands

    int playerHandVal = this->player.calculateHandValue();
    int dealerHandVal = this->dealer.calculateHandValue();

    cout << "Your hand value: " << playerHandVal << endl;
    this->player.showCards();
    cout << "Dealer's hand value : " << dealerHandVal << endl;
    this->dealer.showCards();

    //handle win/lose logic
    if (playerHandVal > 21) { //player hand is invalid (over 21)
        cout << "You've gone bust" << endl;
        win = false;
    } else if (dealerHandVal > 21) { //dealer hand is invalid
        cout << "Dealer has gone bust" << endl;
        win = true;
    } else if (playerHandVal > dealerHandVal) { //player wins
        cout << "Your hand wins" << endl;
        win = true;
    } else if (dealerHandVal > playerHandVal) { //dealer wins
        cout << "Dealer's hand wins" << endl;
        win = false;
    }

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
