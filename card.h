//headers file for the card abstract class

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    private:
        int faceValue;  
        // Numerical value (1-11 for Ace, 10 for face cards, 2-10 for number cards)
       

    public:
        Card();
        Card(int val);
        // Virtual destructor: ensures that when you delete a derived‐Card
        // through a base pointer (Card*), the derived destructor runs too.
        virtual ~Card() = default;

        void setVal(int newVal);
        int getVal() const;
        

        virtual std::string getSuit() const = 0; // pure virtual function
        virtual void setSuit(const std::string& newSuit) = 0; // pure virtual function 
        


};

#endif