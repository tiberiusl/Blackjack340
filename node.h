#ifndef NODE_H
#define NODE_H

#include "card.h"

class Node {
    private:
        Card* data;
        Node* next;
        Node* prev;

    public:
        Node();
        Node(Card* data);
        ~Node();
        
        Card* getData() const;
        Node* getNext() const;
        Node* getPrev() const;

        void setData(Card* newData);
        void setNext(Node* newNext);
        void setPrev(Node* newPrev);
};
#endif