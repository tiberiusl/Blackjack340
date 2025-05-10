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
        bool playGame(); 
        void startGame(); 
        void endGame(bool win);

    public:
        BlackJack(); 
        ~BlackJack(); 
        void play();

};

#endif