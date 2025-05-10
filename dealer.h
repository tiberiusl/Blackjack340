#ifndef DEALER_H
#define DEALER_H

#include "participant.h"

class Dealer : public Participant {
    public:
        //Dealer(); 
        //~Dealer() override; 

        void takeTurn(Deck* myDeck); 

};

#endif