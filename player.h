#ifndef PLAYER_H
#define PLAYER_H

#include "participant.h"
#include <iostream>


class Player : public Participant {

    public:
        //Player(); 
        //~Player() override; 

        void takeTurn(Deck& myDeck) override;
};



#endif