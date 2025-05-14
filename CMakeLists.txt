cmake_minimum_required(VERSION 3.31)
project(Blackjack340)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Blackjack340
        blackjack.cpp
        blackjack.h
        card.cpp
        card.h
        clover.cpp
        clover.h
        dealer.cpp
        dealer.h
        deck.cpp
        deck.h
        diamond.cpp
        diamond.h
        heart.cpp
        heart.h
        linkedlist.cpp
        linkedlist.h
        main.cpp
        node.cpp
        node.h
        participant.cpp
        participant.h
        player.cpp
        player.h
        spade.cpp
        spade.h
        test.cpp
        test.h
        klondike.cpp
        klondike.h)
