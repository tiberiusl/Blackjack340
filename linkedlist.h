#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "card.h"

class LinkedList {
    private:
        Node* head; 
        Node* tail; 
        int count;
//feature/mergeSort
        void split(LinkedList*& left, LinkedList*& right);
        void updateTailAndSize();   
        void mergeSort(LinkedList * topListPtr);

           
//main
    public:
        LinkedList(); 
        ~LinkedList(); 
        void push_back(Card* card); 
        void deleteNode(Card* card); 
        int size() const; 
        void clear(); 
        void mergeSort(); 
        Node* getHead() const; 
        Node* getTail() const; 
        void  mergeLists(LinkedList* listB);
        void  setHead(Node* newHead);
        void  setTail(Node* newTail);
        void  setSize(int newSize);

};

#endif