#include "deck.h"
#include "linkedlist.h"
#include <vector>

Deck::Deck() {
    this->deck = new LinkedList;
}

Deck::~Deck() {
    this->deck->clear();
//to implement    
}

void Deck::takeTurn() { //populates a linkedlist with 52 cards
    std::vector<std::string> values = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::vector<int> scores = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    //Aces have value 11
    for (unsigned int i = 0; i < 13; ++i) {
        Card* spade   = new Spade(scores[i]); //set facevalue of card accordingly
        spade->setName(values[i]); //set name of card accordingly
        this->deck->push_back(spade);

        Card* heart   = new Heart(scores[i]); //set facevalue of card accordingly
        heart->setName(values[i]); //set name of card accordingly
        this->deck->push_back(heart);

        Card* diamond = new Diamond(scores[i]); //set facevalue of card accordingly
        diamond->setName(values[i]); //set name of card accordingly
        this->deck->push_back(diamond);

        Card* clover  = new Clover(scores[i]); //set facevalue of card accordingly
        clover->setName(values[i]); //set name of card accordingly
        this->deck->push_back(clover);
}
}

void Deck::shuffle() {

//to implement    
}

Card* Deck::pop_back() {
    Node* tailNode = this->deck->getTail();

    if (tailNode == nullptr) { //if deck is empty
        return nullptr;
    }
    
    //clone card* of node
    //this enables deleting node from deck
    //while keeping its card* which will enter
    //dealer or player's hand with push_back()
    Card* original = tailNode->getData();
    Card* copy = original->clone();

    //delete Node
    delete original;
    this->deck->deleteNode(tailNode);

    return copy;
}



int Deck::size() const {
    return this->deck->size(); 
}