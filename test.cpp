#include "test.h"
using namespace std;

void Test::TestDeck() {

    cout << "testing deck" << endl;
    cout << "testing deck creation" << endl;
    Deck* newDeck = new Deck();
    cout << "Expected deck size is 0, actual size: " << newDeck->size() << endl;
    cout << "\ntesting fill() method to fill deck with 52 cards" << endl;
    newDeck->fill();
    cout << "\fill() used, expected size is now 52, actual size: " << newDeck->size() << endl;

    cout << "testing suite assignment";
    cout << "\n\n";
    cout << "\nPrinting all cards in deck:\n";
    newDeck->printDeck();
    delete newDeck;  // cleanup

}
void Test::TestCard() {

    //testing Card constructors 
    Card* newHeart = new Heart;
    Card* newClover = new Clover;
    Card* newDiamond = new Diamond;
    Card* newSpade = new Spade;

    cout << "testing printCard() + setters" << endl;
    cout << "all cards should have empty names" << endl;
    cout << "and print their corresponding suite names" << endl;

    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();

    cout << "changing values and names of cards" << endl;
    newHeart->setVal(7);
    newHeart->setName("7");

    newClover->setVal(10);
    newClover->setName("Jack");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    cout << "cards should now print \"name of suite\"" << endl;
    cout << "value of card is stored and not printed" << endl;
    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();
    cout << endl;

    delete newHeart;
    delete newClover;
    delete newDiamond;
    delete newSpade;

}
void Test::TestParticipant() {

    cout << "testing player and dealer" << endl;
    cout << "testing constructors" << endl;
    Player* newPlayer = new Player;
    Dealer* newDealer = new Dealer;

    cout << "If you're seeing this, we didn't crash" << endl;
    cout << "Constructors probably worked" << endl;

    cout << "testing showCards() on empty hand" << endl;
    newPlayer->showCards();
    newDealer->showCards();

    cout << "\n\n";

    cout << "testing calculateHandValue() on empty hand" << endl;
    cout << "should be 0, which prints special dialogue" << endl; 
    cout << newPlayer->calculateHandValue();
    cout << endl;
    cout << newDealer->calculateHandValue();
    cout << endl;

    Card* newHeart = new Heart;
    Card* newClover = new Clover;
    Card* newDiamond = new Diamond;
    Card* newSpade = new Spade;

    //initialize cards
    newHeart->setVal(7);
    newHeart->setName("7");

    newClover->setVal(10);
    newClover->setName("Jack");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    cout << "testing addCard()" << endl;
    cout << "simply calls LinkedList's pushback() with given Card*" << endl;
    cout << "adding cards to player" << endl;
    newPlayer->addCard(newHeart);
    newPlayer->addCard(newClover);
    newPlayer->addCard(newDiamond);
    newPlayer->addCard(newSpade);

    cout << "adding cards to dealer" << endl;
    newDealer->addCard(newDiamond);
    newDealer->addCard(newHeart);

    cout << "Testing showCards() on non-empty hand/list" << endl;
    cout << "show cards should run printCard() of" << endl;
    cout << "all Card* in LinkedList, one per new line" << endl;

    cout << "showing player's cards" << endl;
    newPlayer->showCards();
    cout << "showing dealer's cards" << endl;
    newDealer->showCards();
    cout << endl;

    cout << "Testing calculateHandValue() with newly added cards" << endl;
    cout << "Calculating player's hand, expected to be 37 (7 + 10 + 10 + 10)" << endl;
    cout << newPlayer->calculateHandValue(); //expected to be 37 (7 + 10 + 10 + 10)
    cout << endl;

    cout << "Testing calculateHandValue() with newly added cards" << endl;
    cout << "Calculating dealer's hand, expected to be 17 (10 + 7)" << endl;
    cout << newDealer->calculateHandValue(); //expected to be 17 (10 + 7)
    cout << endl;

    cout << "testing dynamic ace value handling" << endl;
    cout << "changing values of cards" << endl;

    newHeart->setVal(11);
    newHeart->setName("Ace");

    newClover->setVal(11);
    newClover->setName("Ace");

    newDiamond->setVal(10);
    newDiamond->setName("Queen");

    newSpade->setVal(10);
    newSpade->setName("King");

    cout << "new value of cards" << endl;
    newHeart->printCard();
    newClover->printCard();
    newDiamond->printCard();
    newSpade->printCard();

    cout << "recalculating value of hands" << endl;
    cout << "calculating value of player's hand, expected to be 22 (11 + 11 + 10 + 10 - 10 - 10)" << endl;
    cout << "(2 Aces at 11 makes 22, total of 42 means player is over 21)" << endl;
    cout << "(calculateHandValue() should subtract 2 * (-10) from total value)" << endl;
    cout << "(essentially changing the 2 Aces value to 1 each)" << endl;
    cout << newPlayer->calculateHandValue(); //expected to be 22 (11 + 11 + 10 + 10 - 10 - 10) 
    cout << endl;
    cout << "calculating value of dealer's hand, expected to be 21 (11 + 10)" << endl;
    cout << newDealer->calculateHandValue(); //expected to be 21 (11 + 10) 
    cout << endl;

    delete newHeart;
    delete newClover;
    delete newDiamond;
    delete newSpade;

    delete newPlayer;
    delete newDealer;

}

void Test::TestShuffle() {
    cout << "\n=== Entering TestShuffle() ===" << endl;

    // Create and fill the deck
    Deck* deck = new Deck();
    deck->fill();
    
    cout << "\nDeck before shuffling:" << endl;
    deck->printDeck();

    // Shuffle the deck
    deck->shuffle();
    
    cout << "\nDeck after shuffling 1 time:" << endl;
    deck->printDeck();

    for (int i = 0; i < 7; ++i) {

        deck->shuffle();
    }

    cout << "\nDeck after shuffling 7 times:" << endl;
    deck->printDeck();
    
    // Verify deck count remains 52
    if (deck->size() == 52) {
        cout << "\nTestShuffle passed: deck still has 52 cards after shuffling." << endl;
    } else {
        cout << "\nTestShuffle failed: deck count changed after shuffling." << endl;
    }

    //get member called deck from Deck pointer deck
    //to call mergeSort()
    deck->getDeck()->mergeSort();
    cout << "\nDeck after mergeSort():" << endl << endl;
    deck->printDeck();

    delete deck;
}


void Test::TestAll() {
    cout << "\n=== Running All Tests ===\n";

    cout << "\n--- Testing Shuffle ---\n";
    TestShuffle();
    
    cout << "\n--- Testing Deck ---\n";
    TestDeck();
    
    cout << "\n--- Testing Card ---\n";
    TestCard();
    
    cout << "\n--- Testing Participant ---\n";
    TestParticipant();
    
    cout << "\n--- Testing Play() ---\n";
    TestPlay();
    
    cout << "\n=== All Tests Complete ===\n";
}

void Test::TestPlay() {
    BlackJack newBlackjack;
    newBlackjack.play();
}