#ifndef DECK_H
#define DECK_H

#include "linkedlist.h"
#include "card.h"
#include"diamond.h"
#include"heart.h"
#include"spade.h"
#include"clover.h"
#include <random>

class Deck {
    private:
        LinkedList* deck; 
        std::mt19937 generator;

    public:
        Deck(); 
        ~Deck(); 

        void fill();
        void shuffle(); 
        Card* pop_back();
        int size() const; 
        void printDeck() const; //created for testing purposes
        void clearDeck();
        LinkedList* getDeck();
           
};


#endif