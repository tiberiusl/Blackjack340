#ifndef DIAMOND_H
#define DIAMOND_H

#include "card.h"


class Diamond : public Card {
    private:
        std::string suit;

    public:
        Diamond();
        Diamond(int val);
        
        std::string getSuit() const override; 
        void setSuit(const std::string& newSuit) override; 
        

};



#endif