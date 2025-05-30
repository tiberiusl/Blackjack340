#ifndef CLOVER_H
#define CLOVER_H

#include "card.h"

class Clover : public Card {
    private:
        std::string suit;

    public:
        Clover();
        Clover(int val);
        Clover(const Clover& toCopy);
        ~Clover() override = default;

        std::string getSuit() const override; // Get the suit of the card
        Card* clone() const override;
        virtual void printCard() const override;
};

#endif