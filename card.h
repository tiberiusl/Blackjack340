//headers file for the card abstract class

#ifndef CARD_H
#define CARD_H

class Card {
    private:
        int value;  // Numerical value (1-11 for Ace, 10 for face cards, 2-10 for number cards)
        std::string rank; // "Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2

    public:
        Card();
        Card(int val);
        virtual ~Card() = default;

        void setVal(int newVal);
        void setRank(const std::string& newRank);
        int getVal() const;
        std::string getRank() const;

        virtual std::string getSuit() const = 0; // pure virtual function 
        virtual void printCard() const = 0; // pure virtual function


};




#endif