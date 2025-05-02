#include "test.h"
using namespace std;

void Test::Testing() {
    //testing deck
    cout << "\n\n";
    cout << "testing deck creation" << endl;
    Deck* newDeck = new Deck();
    cout << "Expected deck size is 0, actual size: " << newDeck->size() << endl;
    cout << "\ntesting fill() method to fill deck with 52 cards" << endl;
    newDeck->fill();
    cout << "\ntakeTurn() used, expected size is now 52, actual size: " << newDeck->size() << endl;

    //testing suite assignment
    cout << "\n\n";
    cout << "\nPrinting all cards in deck:\n";
    newDeck->printDeck();
    delete newDeck;  // cleanup

    //testing Card constructors 
    Card* newHeart = new Heart;
    Card* newClover = new Clover;
    Card* newDiamond = new Diamond;
    Card* newSpade = new Spade;

    //testing printCard() + setters
    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();

    newHeart->setVal(7);
    newHeart->setName("7");

    newClover->setVal(10);
    newClover->setName("Jack");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();

    //testing player and dealer
    Player* newPlayer = new Player;
    Dealer* newDealer = new Dealer;

    newPlayer->showCards();
    newDealer->showCards();

    cout << "\n\n";

    cout << newPlayer->calculateHandValue();
    cout << endl;
    cout << newDealer->calculateHandValue();
    cout << endl;

    newPlayer->addCard(newHeart);
    newPlayer->addCard(newHeart);
    newPlayer->addCard(newHeart);
    newPlayer->addCard(newHeart);

    newDealer->addCard(newDiamond);
    newDealer->addCard(newDiamond);

    cout << newPlayer->calculateHandValue();
    cout << endl;
    cout << newDealer->calculateHandValue();
    cout << endl;

    delete newPlayer;
    delete newDealer;

}