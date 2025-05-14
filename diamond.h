#ifndef DIAMOND_H
#define DIAMOND_H

#include "card.h"


class Diamond : public Card {
    private:
        std::string suit;

    public:
        Diamond();
        Diamond(int val);
        Diamond(const Diamond& toCopy);
        ~Diamond() override = default;
        
        std::string getSuit() const override; 
        Card* clone() const override;
        virtual void printCard() const override;
    
};



#endif