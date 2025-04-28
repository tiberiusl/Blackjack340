#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
    private:
        Node* head; 
        Node* tail; 
        int count;   
    public:
        LinkedList(); 
        ~LinkedList(); 

        void push_back(Card* card); 
        void deleteNode(Card* card); 
        int size() const; 
        void clear(); 

        Node* getHead() const; 
        Node* getTail() const; 

};

#endif