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

void LinkedList::setHead(Node* newHead) {

    this->head = newHead; // Set the head of the list

}

void LinkedList::setTail(Node* newTail) {

    this->tail = newTail; // Set the tail of the list

}

void LinkedList::setSize(int newSize) {

    this->count = newSize; // Set the size of the list

}

void LinkedList::mergeLists(LinkedList* listB) { //mergest two lists in order, keeps duplicates
    Node* currentA = this->getHead();
    Node* currentB = listB->getHead();
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    int newSize = 0;

    // both lists are empty
    if (currentA == nullptr && currentB == nullptr) {
        return; // exit early
    }

    // merge both lists into one sorted list
    while (currentA != nullptr || currentB != nullptr) {
        Node* nextNode = nullptr;

        if (currentA == nullptr) { // listA empty, take from listB
            nextNode = currentB;
            currentB = currentB->getNext();
        } else if (currentB == nullptr) { // listB empty, take from listA
            nextNode = currentA;
            currentA = currentA->getNext();
        } else if (currentA->getData() < currentB->getData()) { // listA smaller
            nextNode = currentA;
            currentA = currentA->getNext();
        } else { // listB smaller OR equal (<=)
            nextNode = currentB;
            currentB = currentB->getNext();
        }

        // add node to merged list
        if (newHead == nullptr) { // first node (head)
            newHead = nextNode;
            newTail = nextNode;
            newHead->setPrev(nullptr);
        } else {
            newTail->setNext(nextNode);
            nextNode->setPrev(newTail);
            newTail = nextNode;
        }

        newSize++;
    }

    // finish list properly
    if (newTail != nullptr) {
        newTail->setNext(nullptr);
    }

    // set new list info
    this->setHead(newHead);
    this->setTail(newTail);
    this->setSize(newSize);

    // clean up listB
    listB->setHead(nullptr);
    listB->setTail(nullptr);
    listB->setSize(0);
}

void LinkedList::split(LinkedList*& left, LinkedList*& right) {
    if (this->getHead() == nullptr || this->getHead()->getNext() == nullptr) {
        // If 0 or 1 element, no split needed
        left = this;
        right = new LinkedList(); // empty right-side LinkedList
        return;
    }

    Node* slow = this->getHead();
    Node* fast = this->getHead()->getNext();

    // Advance slow by 1 and fast by 2
    // slow gets to middle when fast reaches end of LinkedList
    while (fast != nullptr && fast->getNext() != nullptr) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    // Split point found: slow is the Tail node of the left half
    Node* mid = slow->getNext(); // mid starts right half
    slow->setNext(nullptr);      // break the list
    if (mid != nullptr)  {
       mid->setPrev(nullptr);
    }
    // Create two new LinkedLists
    left = new LinkedList();
    right = new LinkedList();

    // Set left's Head pointer
    left->setHead(this->getHead());
    left->updateTailAndSize();

    // Set right's Head pointer
    right->setHead(mid);
    right->updateTailAndSize();
}

void LinkedList::updateTailAndSize() {
    Node* current = this->getHead();
    Node* Tail = nullptr;
    int size = 0;

    while (current != nullptr) {
        Tail = current;
        current = current->getNext();
        size++;
    }

    this->setTail(Tail);
    this->setSize(size);
}

void LinkedList::mergeSort() {
   mergeSort(this);
}

void LinkedList::mergeSort(LinkedList* topListPtr) {
    if (topListPtr->getHead() == nullptr || topListPtr->getHead()->getNext() == nullptr) {
        return; // Nothing to sort
    }

    LinkedList* left = new LinkedList();
    LinkedList* right = new LinkedList();

    topListPtr->split(left, right); // Split into left and right

    mergeSort(left);  // Sort left half
    mergeSort(right); // Sort right half

    left->mergeLists(right); // Merge left and right into left

    // Copy sorted list into topListPtr
    topListPtr->setHead(left->getHead());
    topListPtr->setTail(left->getTail());
    topListPtr->setSize(left->size());

    // Avoid double deletes by disconnecting left
    left->setHead(nullptr);
    right->setHead(nullptr);

    //free up allocated memory
    delete left;
    delete right;
}
