#ifndef CLOVER_H
#define CLOVER_H

#include "card.h"

class Clover : public Card {
    private:
        std::string suit;

    public:
        Clover();
        Clover(int val);

        std::string getSuit() const override; 
        void setSuit(const std::string& newSuit) override; 


};

#endif