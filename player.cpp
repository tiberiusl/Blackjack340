#include "player.h"
using namespace std;
/*
Player::Player() {
    this->hand = new LinkedList;
// to implement
}

Player::~Player() {
    this->hand->clear();
// to implement
}
*/
void Player::takeTurn(Deck& myDeck) {
    int playerNum;
    int handVal = this->calculateHandValue();
    cout << "Your current hand value: " << handVal << endl;
    this->showCards();
    bool stand = false;
    while (!stand && handVal < 22) { //while handVal is less than 22 or player hasn't chosen stand
        cout << "Enter 1 to hit (add a card to hand) or 0 to stand (end turn): ";
        cin >> playerNum;

        if (playerNum == 1) {
            this->addCard(myDeck.pop_back()); //pop card from deck and add to hand
        } else if (playerNum == 0) {
            stand = true;
        } else {
            continue;
        }

        //update handVal
        handVal = this->calculateHandValue();
    }

// to implement
}