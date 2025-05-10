#ifndef PLAYER_H
#define PLAYER_H

#include "participant.h"
#include <iostream>
#include <sstream>


class Player : public Participant {

    public: 
        void takeTurn(Deck* myDeck) override;
};



#endif