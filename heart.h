#ifndef HEART_H
#define HEART_H
#include "card.h"

class Heart : public Card {
    private:
        std::string suit;

    public:
        Heart();
        Heart(int val);
        
        std::string getSuit() const override; 
        void setSuit(const std::string& newSuit) override; 

        
};

#endif