//headers file for the card abstract class

#ifndef CARD_H
#define CARD_H

#include <string>

const std::string RED = "\033[31m";
const std::string WHITE = "\033[37m";
const std::string GREY = "\033[90m";
const std::string RESET = "\033[0m";

class Card {
    protected:
        int faceValue;  
        // Numerical value (1-11 for Ace, 10 for face cards, 2-10 for number cards)
        std::string name;
        // Stores numerical value as string

        bool facedown = false;
        // the card is face-down/hidden if true, revealed if false

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
        virtual void printCard() const = 0; //prints name of card + suite of card

        bool getFaceDown() const;
        void setFaceDown(bool newFaceDown);
        void DisplayCard() const;

};

bool operator==(const Card& lhs, const Card& rhs);
bool operator<(const Card& lhs, const Card& rhs);
bool operator>(const Card& lhs, const Card& rhs);
#endif