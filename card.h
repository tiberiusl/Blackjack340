//headers file for the card abstract class

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    protected:
        int faceValue;  
        // Numerical value (1-11 for Ace, 10 for face cards, 2-10 for number cards)
        std::string name;
        // Stores numerical value as string

    public:
        Card();
        Card(int val);
        Card(const Card& toCopy);
        // Virtual destructor: ensures that when you delete a derived‐Card
        // through a base pointer (Card*), the derived destructor runs too.
        virtual ~Card() = default;

        void setVal(int newVal);
        int getVal() const;
        std::string getName() const;
        void setName(const std::string& newName);
        

        virtual std::string getSuit() const = 0; // pure virtual function
        virtual Card* clone() const = 0;
        //virtual void setSuit(const std::string& newSuit) = 0; // pure virtual function 
        

};

bool operator==(const Card& lhs, const Card& rhs);
bool operator<(const Card& lhs, const Card& rhs);
bool operator>(const Card& lhs, const Card& rhs);
#endif