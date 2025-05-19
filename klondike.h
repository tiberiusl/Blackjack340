#ifndef KLONDIKE_H
#define KLONDIKE_H

#include "deck.h"

enum Actions {EXIT_GAME, DRAW_CARD, MOVE_CARD};

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
    klondike(const klondike& original);
    klondike& operator=(const klondike& original);
    void play();
    void startGame() const;
    void showBoard() const;
    int getUserMove();
    void drawCard() const;
    void moveCard();
    bool moveCardCheck(Deck& source, Deck& target, int numCards = 1) const;
    Deck* getTargetDeck(const std::string& initials) const;
    bool isTableauToTableau(const Deck& source, const Deck& target) const;
};



#endif //KLONDIKE_H
