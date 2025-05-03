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

    //all cards should have empty names
    //and print their corresponding suite names
    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();

    //changing values and names of cards
    newHeart->setVal(7);
    newHeart->setName("7");

    newClover->setVal(10);
    newClover->setName("Jack");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    //cards should now print "name of suite"
    //value of card is stored and not printed
    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();
    

    //testing player and dealer
    Player* newPlayer = new Player;
    Dealer* newDealer = new Dealer;

    //testing showCards() on empty hand
    newPlayer->showCards();
    newDealer->showCards();

    cout << "\n\n";

    //testing calculateHandValue() on empty hand
    //should be 0, which prints special dialogue 
    cout << newPlayer->calculateHandValue();
    cout << endl;
    cout << newDealer->calculateHandValue();
    cout << endl;

    //testing addCard()
    //simply calls LinkedList's pushback() with given Card*
    newPlayer->addCard(newHeart);
    newPlayer->addCard(newClover);
    newPlayer->addCard(newDiamond);
    newPlayer->addCard(newSpade);

    newDealer->addCard(newDiamond);
    newDealer->addCard(newHeart);

    //show cards should run printCard() of
    //all Card* in LinkedList, one per new line
    newPlayer->showCards();
    newDealer->showCards();
    cout << endl;

    cout << newPlayer->calculateHandValue(); //expected to be 37 (7 + 10 + 10 + 10)
    cout << endl;
    cout << newDealer->calculateHandValue(); //expected to be 17 (10 + 7)
    cout << endl;

    //testing dynamic ace value handling

    newHeart->setVal(11);
    newHeart->setName("Ace");

    newClover->setVal(11);
    newClover->setName("Ace");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    cout << newPlayer->calculateHandValue(); //expected to be 22 (11 + 11 + 10 + 10 - 10 - 10) 
    cout << endl;
    cout << newDealer->calculateHandValue(); //expected to be 21 (11 + 10) 
    cout << endl;
    
    delete newHeart;
    delete newClover;
    delete newDiamond;
    delete newSpade;

    delete newPlayer;
    delete newDealer;

}