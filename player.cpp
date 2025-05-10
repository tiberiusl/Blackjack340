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
void Player::takeTurn(Deck* myDeck) {
    string input;
    int playerNum;
    int handVal = this->calculateHandValue();
    bool stand = false;

    while (!stand && handVal < 22) { //while handVal is less than 22 or player hasn't chosen stand
        cout << "Your current hand value: " << handVal << endl;
        this->showCards();
        cout << "Enter 1 to hit (add a card to hand) or 0 to stand (end turn): ";
        getline(cin, input); //get whole line of user's input
        stringstream ss(input); //create stringstream with user input

        //if stringstream is unable to extract an int
        //or if int is not 1 or 0
        if (!(ss >> playerNum) || (playerNum != 0 && playerNum != 1)) {
            cout << "Invalid input. Please enter 0 or 1.\n";
            continue;
        } else if (playerNum == 1) {
            this->addCard(myDeck->pop_back()); //pop card from deck and add to hand
            handVal = this->calculateHandValue(); //update handVal
        } else if (playerNum == 0) {
            stand = true;
        }
    }

// to implement
}