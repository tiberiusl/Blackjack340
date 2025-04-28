#ifndef PLAYER_H
#define PLAYER_H

#include "participant.h"
#include <iostream>

class Player : public Participant {

    public:
        Player(); 
        ~Player(); 

        void takeTurn() override; 
        void showCards() const; 
        int calculateHandValue() const; 

};



#endif