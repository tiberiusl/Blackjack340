#ifndef KLONDIKE_H
#define KLONDIKE_H

#include "deck.h"

class klondike {
private:
    Deck* deck;
    Deck* drawPile;
    Deck* spadeFoundation;
    Deck* heartFoundation;
    Deck* diamondFoundation;
    Deck* cloverFoundation;
    Deck* tableau1;
    Deck* tableau2;
    Deck* tableau3;
    Deck* tableau4;
    Deck* tableau5;
    Deck* tableau6;
    Deck* tableau7;
public:
    klondike();
    ~klondike();
    // copy constructor
    // copy assignment operator
    void play();
    void startGame();
    void showBoard() const;
    int userMove();
    bool moveCardCheck(Deck& source, Deck& target) const;
    Deck* getTargetDeck(const std::string& initials) const;
};



#endif //KLONDIKE_H
