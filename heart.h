#ifndef HEART_H
#define HEART_H
#include "card.h"

class Heart : public Card {
    private:
        std::string suit;

    public:
        Heart();
        Heart(int val);
        Heart(const Heart& toCopy);
        ~Heart() override = default;
        
        std::string getSuit() const override; // Get the suit of the card
        Card* clone() const override;
        virtual void printCard() const override;
        
};

#endif