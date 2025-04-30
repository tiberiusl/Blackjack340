#ifndef DECK_H
#define DECK_H

#include "linkedlist.h"
#include"diamond.h"
#include"heart.h"
#include"spade.h"
#include"clover.h"

class Deck {
    private:
        LinkedList* deck; 
        

    public:
        Deck(); 
        ~Deck(); 

        void takeTurn();
        void shuffle(); 
        Card* pop_back();
        int size() const; 
           
};


#endif