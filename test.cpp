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

    newPlayer->showCards();
    newDealer->showCards();
    cout << endl;

    cout << "got  here" << endl;

    cout << newPlayer->calculateHandValue(); //expected to be 28 (7 * 4)
    cout << endl;
    cout << newDealer->calculateHandValue(); //expected to be 20 (2 * 10)
    cout << endl;

    cout << "got  here 2" << endl;

    //testing clear() & dynamic ace value handling
    //should empty hand

    newHeart->setVal(11);
    newHeart->setName("Ace");

    newClover->setVal(11);
    newClover->setName("Ace");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    newPlayer->getHand()->clear();
    newDealer->getHand()->clear();

    cout << newPlayer->calculateHandValue(); //expected to be 0 
    cout << endl;
    cout << newDealer->calculateHandValue(); //expected to be 0 
    cout << endl;

    newPlayer->addCard(newHeart);
    newPlayer->addCard(newSpade);

    cout << newPlayer->calculateHandValue() << endl; //expected 21 (11 + 10)

    newPlayer->addCard(newDiamond);

    cout << newPlayer->calculateHandValue() << endl; //expected 21 (1 + 10 + 10)

    delete newPlayer;
    delete newDealer;

}