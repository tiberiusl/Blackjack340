#include "deck.h"
#include "linkedlist.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

Deck::Deck() {
    this->deck = new LinkedList;
}

Deck::~Deck() {
    deck->clear();
    delete deck;
    
}

void Deck::clearDeck() {
    this->deck->clear();
}

void Deck::fill() { //populates a linkedlist with 52 cards
    std::vector<std::string> values = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
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
    // 1) Cut the list into two halves
    //std::cout << "[SHUFFLE] start\n" << std::flush;
    LinkedList* leftHalf = nullptr;
    LinkedList* rightHalf = nullptr;
    this->deck->split(leftHalf, rightHalf);
    /*std::cout 
      << "[SHUFFLE] after split: leftSize=" << leftHalf->size() 
      << " rightSize=" << rightHalf->size() << "\n" 
      << std::flush;*/

    // 2) Drain each half into vectors for easier manipulation
    std::vector<Card*> leftBuffer;
    std::vector<Card*> rightBuffer;
    
    //std::cout << "[SHUFFLE] draining leftHalf\n" << std::flush;
    while (leftHalf->size() > 0) {
        leftBuffer.push_back(leftHalf->pop_back());
    }

    //std::cout << "[SHUFFLE] draining rightHalf\n" << std::flush;
    while (rightHalf->size() > 0) {
        rightBuffer.push_back(rightHalf->pop_back());
    }

    // 3) Restore true top-to-bottom order
    std::reverse(leftBuffer.begin(), leftBuffer.end());
    std::reverse(rightBuffer.begin(), rightBuffer.end());

    // 4) Set up random number generator for realistic riffle shuffle
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> packetSize(1, 4);

    //std::cout << "[SHUFFLE] interleaving\n" << std::flush;
    // 5) Riffle shuffle: interleave random size packets from each half
    std::vector<Card*> shuffled;
    while (!leftBuffer.empty() || !rightBuffer.empty()) {
        // Handle remaining cards if one buffer is empty
        if (leftBuffer.empty()) {
            shuffled.insert(shuffled.end(), rightBuffer.begin(), rightBuffer.end());
            break;
        }
        if (rightBuffer.empty()) {
            shuffled.insert(shuffled.end(), leftBuffer.begin(), leftBuffer.end());
            break;
        }

        // Take random packet from left
        int leftCount = std::min(packetSize(generator), (int)leftBuffer.size());
        for (int i = 0; i < leftCount; i++) {
            shuffled.push_back(leftBuffer.back());
            leftBuffer.pop_back();
        }

        // Take random packet from right
        int rightCount = std::min(packetSize(generator), (int)rightBuffer.size());
        for (int i = 0; i < rightCount; i++) {
            shuffled.push_back(rightBuffer.back());
            rightBuffer.pop_back();
        }
    }

    //std::cout << "[SHUFFLE] done interleaving\n" << std::flush;
    // 6) Clear original deck and rebuild with shuffled cards
    /*std::cout 
      << "[SHUFFLE] before clear: deckSize=" << this->deck->size() 
      << "  shuffledCount=" << shuffled.size() 
      << "\n" << std::flush;*/

    
    this->deck->setHead(nullptr);
    this->deck->setTail(nullptr);
    this->deck->setSize(0);

    /*std::cout 
      << "[SHUFFLE] after clear: deckSize=" << this->deck->size() 
      << "\n" << std::flush;*/

    for (Card* card : shuffled) {
        this->deck->push_back(card);
    }

    /*int idx = 0;
    for (Card* card : shuffled) {
        std::cout 
          << "[SHUFFLE] push_back #" << ++idx 
          << " -> " << card->getName() 
          << " of " << card->getSuit() 
          << "\n" << std::flush;
        this->deck->push_back(card);
    }*/

    /*std::cout 
      << "[SHUFFLE] after rebuild: deckSize=" << this->deck->size() 
      << "\n" << std::flush;*/

    // Clean up temporary lists
    delete leftHalf;
    delete rightHalf;
}

Card* Deck::pop_back() {
    std::cout << "[DEBUG] Deck::pop_back()\n";
    Node* tailNode = this->deck->getTail();
    if (tailNode == nullptr) return nullptr;
    
    // 1) Clone the card so the caller owns this new copy
    Card* copy = tailNode->getData()->clone();
    
    // 2) Delete the node (this also deletes the original Card* stored in that node)
    this->deck->deleteNode(tailNode);
    
    // 3) Return the clone
    return copy;
    
}

//for testing purposes only
void Deck::printDeck() const {
    Node* current = this->deck->getHead();
    int count = 1;
    
    while (current != nullptr) {
        Card* card = current->getData();
        std::cout << count << ". " << card->getName() << " of " << card->getSuit() << " ";
        if (count % 13 == 0) std::cout << std::endl;  
        current = current->getNext();
        count++;
    }
    std::cout << std::endl;
}

int Deck::size() const {
    return this->deck->size(); 
}