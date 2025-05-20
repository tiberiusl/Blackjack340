#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "linkedlist.h"
#include "spade.h"
#include "clover.h"
#include "diamond.h"
#include "heart.h"
#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "blackjack.h"
#include "klondike.h"

class Test{
    public:
        void TestAll();
        void TestDeck();
        void TestCard();
        void TestParticipant();
        void TestShuffle();
        void TestPlay();

        void TestMenu();
        void TestDisplayCard();
        void TestPlayKlondike();
};

#endif