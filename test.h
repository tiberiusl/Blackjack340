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

class Test{
    public:
        void TestAll();
        void TestDeck();
        void TestCard();
        void TestParticipant();
};

#endif