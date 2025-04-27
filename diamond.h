#ifndef DIAMOND_H
#define DIAMOND_H

#include "card.h"
#include <string>

class Diamond : public Card {
    private:
        std::string suit;

    public:
        Diamond();
        Diamond(int val);
        
        std::string getSuit() const override; // Get the suit of the card
        

};



#endif