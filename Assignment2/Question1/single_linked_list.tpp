#include "single_linked_list.h"

#include <iostream>
#include <stdexcept>

using namespace std;

/*
 * ==========================
 * CONSTRUCTOR AND DESTRUCTOR
 * ==========================
 */

// Constructor
template <typename TData>
SingleLinkedList<TData>::SingleLinkedList() : pHead(nullptr), pTail(nullptr), num_items(0) {}

// Destructor
template <typename TData>
SingleLinkedList<TData>::~SingleLinkedList() {
    Node<TData>* currentNode = pHead;

    while (currentNode != nullptr) {
        Node<TData>* nextNode = currentNode->pNext;
        delete currentNode;
        currentNode = nextNode;
    }

    pHead = nullptr;
    pTail = nullptr;
    num_items = 0;
}

/*
 * ======================
 * PUSH AND POP FUNCTIONS
 * ======================
 */

// Adds item to front of the list
template <typename TData>
void SingleLinkedList<TData>::push_front(const TData& item) {
    Node<TData>* newNode = new Node<TData>(item, pHead);
    pHead = newNode;

    if (pTail == nullptr) {
        pTail = newNode;
    }
    num_items++;
}

// Adds item to back of the list
template <typename TData>
void SingleLinkedList<TData>::push_back(const TData& item) {
    Node<TData>* newNode = new Node<TData>(item, nullptr);

    if (pTail == nullptr) {
        pHead = newNode;
        pTail = newNode;
    } else {
        pTail->pNext = newNode;
        pTail = newNode;
    }
    num_items++;
}

// Removes first item in the list
template <typename TData>
void SingleLinkedList<TData>::pop_front() {
    if (pHead == nullptr) {
        throw std::invalid_argument("Attempt to call pop_front() on an empty list");
    }

    Node<TData>* oldHead = pHead;
    pHead = pHead->pNext;
    delete oldHead;

    if (pHead == nullptr) {
        pTail = nullptr;
    }
    num_items--;
}

// Remove last item in the list
template <typename TData>
void SingleLinkedList<TData>::pop_back() {
    if (pHead == nullptr) {
        throw std::invalid_argument("Attempt to call pop_back() on an empty list");
    }

    if (pHead == pTail) {
        delete pHead;
        pHead = nullptr;
        pTail = nullptr;
    } else {
        Node<TData>* currentNode = pHead;

        while (currentNode->pNext != pTail) {
            currentNode = currentNode->pNext;
        }

        delete pTail;
        pTail = currentNode;
        pTail->pNext = nullptr;
    }

    num_items--;
}

/*
 * ================
 * ACCESS FUNCTIONS
 * ================
 */

// Gets the first element in the list
template <typename TData>
TData& SingleLinkedList<TData>::front() {
    if (empty()) {
        throw std::out_of_range("Attempt to call front() on an empty list");
    }
    return pHead->data;
}

// Gets the last element in the list
template <typename TData>
TData& SingleLinkedList<TData>::back() {
    if (empty()) {
        throw std::out_of_range("Attempt to call back() on an empty list");
    }
    return pTail->data;
}

/*
 * =================
 * UTILITY FUNCTIONS
 * =================
 */

// Returns true if the list is empty
template <typename TData>
bool SingleLinkedList<TData>::empty() const {
    return num_items == 0;
}

// Inserts item at specified index, or at the back if index is out of range
template <typename TData>
void SingleLinkedList<TData>::insert(size_t index, const TData& item) {
    if (index == 0) {
        push_front(item);
    } else if (index >= num_items) {
        push_back(item);
    } else {
        Node<TData>* currentNode = pHead;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->pNext;
        }

        Node<TData>* newNode = new Node<TData>(item, currentNode->pNext);
        currentNode->pNext = newNode;
        num_items++;
    }
}

// Removes item at specified index and returns true if successful
template <typename TData>
bool SingleLinkedList<TData>::remove(size_t index) {
    if (index == 0) {
        pop_front();
    } else if (index >= num_items) {
        return false;
    } else {
        Node<TData>* currentNode = pHead;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->pNext;
        }

        Node<TData>* removeNode = currentNode->pNext;
        currentNode->pNext = removeNode->pNext;

        if (removeNode == pTail) {
            pTail = currentNode;
        }
        delete removeNode;
        num_items--;
    }
    return true;
}

// Returns the index of the first occurrence of the item or returns the size of the list if not found
template <typename TData>
size_t SingleLinkedList<TData>::find(const TData& item) const {
    Node<TData>* currentNode = pHead;
    size_t index = 0;

    while (currentNode != nullptr) {
        if (currentNode->data == item) {
            return index;
        }
        currentNode = currentNode->pNext;
        index++;
    }
    return num_items;
}

// Prints the list
template <typename TData>
void SingleLinkedList<TData>::printList() const {
    Node<TData>* current = pHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->pNext;
    }
    cout << endl;
}
