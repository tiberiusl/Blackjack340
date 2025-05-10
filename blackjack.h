#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "player.h"
#include "dealer.h"
#include "deck.h"
#include <sstream>

class BlackJack {
    private:
        Player* player; 
        Dealer* dealer; 
        Deck* deck; 
        int playGame(); 
        void startGame(); 
        void endGame(int win);

    public:
        BlackJack(); 
        ~BlackJack(); 
        void play();

};

#endif