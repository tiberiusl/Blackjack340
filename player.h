#ifndef PLAYER_H
#define PLAYER_H

#include "participant.h"

class Player : public Participant {

    public:
        //Player(); 
        //~Player() override; 

        void takeTurn(Deck& myDeck) override;
};



#endif