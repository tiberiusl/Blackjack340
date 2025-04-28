#include "linkedlist.h"

LinkedList::LinkedList() {

    this->head = nullptr; // Initialize head to nullptr
    this->tail = nullptr; // Initialize tail to nullptr
    this->count = 0; // Initialize count to 0

}

LinkedList::~LinkedList() {

    clear(); // Clear the list when the LinkedList object is destroyed

}

void LinkedList::push_back(Card* card) {

//to implement
}

void LinkedList::deleteNode(Card* card) {

//to implement
}

int LinkedList::size() const {

    return this->count; // Return the size of the list

}

void LinkedList::clear() {

//to implement
}

Node* LinkedList::getHead() const {

    return this->head; // Return the head of the list

}

Node* LinkedList::getTail() const {

    return this->tail; // Return the tail of the list

}
