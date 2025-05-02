#ifndef PLAYER_H
#define PLAYER_H

#include "participant.h"
#include "deck.h"
#include <iostream>

class Player : public Participant {

    public:
        Player(); 
        ~Player(); 

        void takeTurn(Deck& myDeck) override; 
};



#endif