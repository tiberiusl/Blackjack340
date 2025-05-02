#include <iostream>
#include "linkedlist.h"
#include "spade.h"
#include "clover.h"
#include "diamond.h"
#include "heart.h"
#include "deck.h"
using namespace std;

int main() {
    //testing deck
    cout << "\n\n\n\n\n";
    cout << "testing deck creation" << endl;
    Deck* newDeck = new Deck();
    cout << "Expected deck size is 0, actual size: " << newDeck->size() << endl;
    newDeck->fill();
    cout << "takeTurn() used, expected size is now 52, actual size: " << newDeck->size() << endl;

    //testing suite assignment
    cout << "\nPrinting all cards in deck:\n";
    newDeck->printDeck();
    delete newDeck;  // cleanup

    return 0;
}