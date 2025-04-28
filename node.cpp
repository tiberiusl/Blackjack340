#include "node.h"

Node::Node() {

    this->data = nullptr; 
    this->next = nullptr; 
    this->prev = nullptr; 
}

Node::Node(Card* data) {

    this->data = data; 
    this->next = nullptr; 
    this->prev = nullptr; 
}

Node::~Node() {

    // Destructor implementation
    delete data; 
    data = nullptr; 
    next = nullptr; 
    prev = nullptr; 
}

Card* Node::getData() const {

    return this->data; 
}

Node* Node::getNext() const {

    return this->next; 
}

Node* Node::getPrev() const {

    return this->prev; 
}

void Node::setData(Card* newData) {

    this->data = newData; 
}

void Node::setNext(Node* newNext) {

    this->next = newNext; 
}

void Node::setPrev(Node* newPrev) {

    this->prev = newPrev; 
}

