#ifndef SPADE_H
#define SPADE_H
#include "card.h"

class Spade : public Card {
    private:
        std::string suit;

    public:
        Spade();
        Spade(int val);
        
        std::string getSuit() const override; // Get the suit of the card
        
};

#endif