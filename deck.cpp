#include "deck.h"
#include "linkedlist.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>

Deck::Deck() {
    this->deck = new LinkedList;
    this->generator.seed(static_cast<unsigned int>(time(nullptr)));
}

Deck::~Deck() {
    deck->clear();
    delete deck;
    
}

Deck::Deck(const Deck& original) {
    this->deck = new LinkedList;
    this->generator.seed(static_cast<unsigned int>(time(nullptr)));
    Node* current = original.deck->getHead();
    while (current != nullptr) {
        Card* cardCopy = current->getData()->clone();
        this->deck->push_back(cardCopy);
        current = current->getNext();
    }
}

Deck& Deck::operator=(const Deck& original) {
    if (this == &original) return *this;
    this->deck->clear();
    Node* current = original.deck->getHead();
    while (current != nullptr) {
        Card* cardCopy = current->getData()->clone();
        this->deck->push_back(cardCopy);
        current = current->getNext();
    }
    return *this;
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
    LinkedList* leftHalf = new LinkedList();
    LinkedList* rightHalf = new LinkedList();
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
    //std::cout << "[DEBUG] Deck::pop_back()\n";
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

LinkedList* Deck::getDeck() {
    return this->deck;
}

//
void Deck::KlondikeFill() const {
    for (int i = 1; i < 14; ++i) {
        Card* spade = new Spade(i);
        this->deck->push_back(spade);
        Card* heart = new Heart(i);
        this->deck->push_back(heart);
        Card* diamond = new Diamond(i);
        this->deck->push_back(diamond);
        Card* clover = new Clover(i);
        this->deck->push_back(clover);
    }
}
void Deck::KlondikePrintDeck() const {
    const Node* current = this->deck->getHead();
    while (current) {
        current->getData()->DisplayCard();
        std::cout << " ";
        current = current->getNext();
    }
}
void Deck::MoveLastCardTo(Deck &targetDeck) {
    Card* card = this->pop_back();
    if (card != nullptr) {
        targetDeck.getDeck()->push_back(card);
    }
}
void Deck::MoveCardSequence(Deck &targetDeck, const int numCards) {
    if (numCards <= 0 || numCards > this->size()) {
        return;
    }

    // first collect cards and their face-up states
    std::vector<std::pair<Card*, bool>> cardsToMove;
    Node* current = this->deck->getTail();
    for (int i = 0; i < numCards && current != nullptr; i++) {
        cardsToMove.push_back({current->getData()->clone(), !current->getData()->getFaceDown()});
        current = current->getPrev();
    }

    // now move the cards in the correct order (from bottom to top)
    for (int i = cardsToMove.size() - 1; i >= 0; i--) {
        Card* cardCopy = cardsToMove.at(i).first;
        cardCopy->setFaceDown(false);
        targetDeck.getDeck()->push_back(cardCopy);
        // delete the original card from the source deck
        if (this->deck->getTail() != nullptr) {
            this->deck->deleteNode(this->deck->getTail());
        }
    }

    // if there are any cards left in the source pile, make sure the top one is face-up
    if (this->deck->getTail() != nullptr) {
        this->deck->getTail()->getData()->setFaceDown(false);
    }
}
bool Deck::IsValidCardSequence(int startIndex) const {
    // get to the starting point of the sequence
    Node* current = this->deck->getTail();
    Node* bottomCard = current;
    
    // move to the bottom card of the sequence being moved
    for (int i = 0; i < startIndex; i++) {
        if (!current) return false;
        current = current->getPrev();
        bottomCard = current;
    }
    
    if (!bottomCard) return false;

    /*
    // debug output
    std::cout << "Starting sequence check from: ";
    bottomCard->getData()->DisplayCard();
    std::cout << std::endl;
    */

    // check the sequence from bottom to top
    current = bottomCard;
    while (current && current->getNext()) {
        Card* lowerCard = current->getData();
        Card* upperCard = current->getNext()->getData();
        
        // skip face-down cards
        if (lowerCard->getFaceDown() || upperCard->getFaceDown()) {
            std::cout << "Cannot move face-down cards" << std::endl;
            return false;
        }

        /*
        // debug output
        std::cout << "Comparing: ";
        lowerCard->DisplayCard();
        std::cout << " with ";
        upperCard->DisplayCard();
        std::cout << std::endl;
        */
        
        // check if the sequence follows sequence rules
        if (lowerCard->getColor() == upperCard->getColor()) {
            std::cout << "Invalid: Same colors" << std::endl;
            return false;
        }
        if (lowerCard->getVal() != upperCard->getVal() + 1) {
            std::cout << "Invalid: Not descending sequence" << std::endl;
            return false;
        }
        current = current->getNext();
    }

    /*
    debug output
    std::cout << "Sequence is valid" << std::endl;
    */

    return true;
}