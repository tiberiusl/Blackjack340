//header file for abstarct class Participant

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "LinkedList.h"
#include "card.h"
#include <vector>

class Participant {
    protected:
        LinkedList hand; 
        

    public:
        Participant(); 
        virtual ~Participant(); 

        void addCard(Card* card); 
        void showCards() const; 
        void clearHand(); 
        int calculateHandValue() const; 
        
        virtual void takeTurn() = 0; 

};

#endif