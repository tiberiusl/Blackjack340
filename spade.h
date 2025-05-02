#ifndef SPADE_H
#define SPADE_H
#include "card.h"

class Spade : public Card {
    private:
        std::string suit;

    public:
        Spade();
        Spade(int val);
        Spade(const Spade& toCopy);
        ~Spade() override;
        
        std::string getSuit() const override; // Get the suit of the card
        Card* clone() const override;
        virtual void printCard() const override;
};

#endif