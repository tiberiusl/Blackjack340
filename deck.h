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
        // needed a copy constructor to use for the klondike copy constructor
        Deck(const Deck& original);
        Deck& operator=(const Deck& original);

        void fill();
        void shuffle(); 
        Card* pop_back();
        int size() const; 
        void printDeck() const; //created for testing purposes
        void clearDeck();
        LinkedList* getDeck();

        void KlondikeFill() const;
        void KlondikePrintDeck() const;
        void MoveLastCardTo(Deck& targetDeck);
        void MoveCardSequence(Deck& targetDeck, int numCards);
        bool IsValidCardSequence(int startIndex) const;
};


#endif