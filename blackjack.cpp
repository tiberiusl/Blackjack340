#include "blackjack.h"
#include <iostream>
using namespace std;

BlackJack::BlackJack() {
    this->player = new Player();
    this->dealer = new Dealer();
    this->deck = new Deck();
}

BlackJack::~BlackJack() {
    delete this->player;
    delete this->dealer;
    delete this->deck;
//to implement    
}

int BlackJack::playGame() {
    //initialize player, dealer, and deck
    this->startGame();
    bool win; //shows if player wins or loses

    //player(s) and dealer take their turns
    this->player->takeTurn(this->deck);
    this->dealer->takeTurn(this->deck);

    //display final hands

    int playerHandVal = this->player->calculateHandValue();
    int dealerHandVal = this->dealer->calculateHandValue();

    cout << "Your hand value: " << playerHandVal << endl;
    this->player->showCards();
    cout << "Dealer's hand value : " << dealerHandVal << endl;
    this->dealer->showCards();

    //handle win/lose logic
    if (playerHandVal > 21) { //player hand is invalid (over 21)
        cout << "You've gone bust" << endl;
        win = false;
    } else if (dealerHandVal > 21) { //dealer hand is invalid
        cout << "Dealer has gone bust" << endl;
        win = true;
    } else if (playerHandVal == dealerHandVal) {
        cout << "Round is tied" << endl;
    } else if (playerHandVal > dealerHandVal) { //player wins
        cout << "Your hand wins" << endl;
        win = true;
    } else if (dealerHandVal > playerHandVal) { //dealer wins
        cout << "Dealer's hand wins" << endl;
        win = false;
    }

    //clear hands
    this->deck->clearDeck();
    this->player->getHand()->clear();
    this->dealer->getHand()->clear();

    return win;

}

void BlackJack::startGame() {
    this->deck->fill(); //fill deck
    //cout << "DEBUG: showing deck after fill()" << endl;
    //this->deck->printDeck();
    this->deck->shuffle(); ////shuffle deck
    //cout << "DEBUG: showing deck after shuffle()" << endl;
    //this->deck->printDeck();

    for (unsigned int i = 0; i < 2; ++i) { //add two cards to dealer + player
        this->player->addCard(this->deck->pop_back());
        this->dealer->addCard(this->deck->pop_back());
    }
}

void BlackJack::endGame(int win) {
    //set up ostream
    //use win to determine if player wins or loses or draws
    //print winner of round + winning hand/hand value to text file
    cout << "endGame() called" << endl;
//to implement        
}

void BlackJack::play() {
    string input;
    int exit = 0;
    bool win;
    while (exit == 0) {
        int userIn = -1; //represents player input
        win = this->playGame();
        this->endGame(win);
        while (userIn != 0 && userIn != 1) {
            cout << "Keep playing? Enter 1 to exit, 0 to continue: ";
            getline(cin, input);
            stringstream ss(input);
            //if stringstream can't extract int
            //or int is out of range
            if (!(ss >> userIn) || userIn != 0 && userIn != 1) {
                cout << "Invalid input. Please enter 1 or 0" << endl << endl;
            }
        }
        exit = userIn;
    }
}