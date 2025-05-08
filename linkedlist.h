#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "card.h"

class LinkedList {
    protected:
        Node* head; 
        Node* tail; 
        int count;
        //void split(LinkedList*& left, LinkedList*& right);
        //void updateTailAndSize();   
        //void mergeSort(LinkedList * topListPtr);

           
    public:
        LinkedList(); 
        ~LinkedList(); 
        void push_back(Card* card); 
        void deleteNode(Node* toDelete); 
        int size() const; 
        void clear(); 
        void mergeSort(); 
        Node* getHead() const; 
        Node* getTail() const; 
        void  mergeLists(LinkedList* listB);
        void  setHead(Node* newHead);
        void  setTail(Node* newTail);
        void  setSize(int newSize);
        void split(LinkedList*& left, LinkedList*& right);
        void updateTailAndSize();   
        void mergeSort(LinkedList * topListPtr);
        Card* pop_back();

};

#endif