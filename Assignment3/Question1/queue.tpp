#include "queue.h"

#include <iostream>

using namespace std;

/*
 * ==========================
 * CONSTRUCTOR AND DESTRUCTOR
 * ==========================
 */

// Constructor
template <typename TData>
Queue<TData>::Queue() : pFront(nullptr), pBack(nullptr), num_items(0) {}

// Destructor
template <typename TData>
Queue<TData>::~Queue() {
    while (!empty()) {
        pop();
    }
}

/*
 * ======================
 * PUSH AND POP FUNCTIONS
 * ======================
 */

// Adds item to the back of the queue
template <typename TData>
void Queue<TData>::push(const TData& item) {
    if (pFront == nullptr) {
        pBack = new Node<TData>(item, nullptr);
        pFront = pBack;
    } else {
        pBack->pNext = new Node<TData>(item, nullptr);
        pBack = pBack->pNext;
    }
    num_items++;
}

// Removes item from the front of the queue
template <typename TData>
void Queue<TData>::pop() {
    Node<TData>* pOldFront = pFront;
    pFront = pFront->pNext;
    if (pFront == nullptr) {
        pBack = nullptr;
    }
    delete pOldFront;
    num_items--;
}

/*
 * =================
 * UTILITY FUNCTIONS
 * =================
 */

// Gets the element at the front of the queue
template <typename TData>
TData& Queue<TData>::front() {
    return pFront->data;
}

// Returns true if the queue is empty
template <typename TData>
bool Queue<TData>::empty() const {
    return num_items == 0;
}

// Returns the number of items in the queue
template <typename TData>
size_t Queue<TData>::size() const {
    return num_items;
}

// Moves the element at the front of the queue to the back
template <typename TData>
void Queue<TData>::moveToRear() {
    // No need to switch if size is <= 1
    if (size() > 1) {
        TData oldFrontData = front();
        pop();
        push(oldFrontData);
    }
}

// Prints the queue
template <typename TData>
void Queue<TData>::printQueue() const {
    Node<TData>* current = pFront;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->pNext;
    }
    cout << endl;
}