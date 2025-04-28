//header file for abstarct class Participant

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "LinkedList.h"
#include "card.h"

class Participant {
    protected:
        LinkedList<Card*> hand; // List of cards in hand
        

    public:
        Participant(); // Default constructor
        virtual ~Participant(); // Destructor

        void addCard(Card* card); // Add a card to the hand
        void showCards() const; // Show all cards in hand
        void clearHand(); // Clear the hand
        int calculateHandValue() const; // Calculate the total value of the hand
        
        virtual void takeTurn() = 0; // Pure virtual function for taking a turn

};

#endif