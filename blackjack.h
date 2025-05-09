#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "player.h"
#include "dealer.h"
#include "deck.h"

class BlackJack {
    private:
        Player player; 
        Dealer dealer; 
        Deck deck; 
        void playGame(); 
        void startGame(); 
        void endGame(); 

    public:
        BlackJack(); 
        ~BlackJack(); 
        void play();

};

#endif