#include "single_linked_list.h"

#include <stdexcept>

/*
 * ==========================
 * CONSTRUCTOR AND DESTRUCTOR
 * ==========================
 */

// Constructor
template <typename TData>
SingleLinkedList<TData>::SingleLinkedList() {
    pHead = nullptr;
    pTail = nullptr;
    num_items = 0;
}

// Destructor
template <typename TData>
SingleLinkedList<TData>::~SingleLinkedList() {
    // FIXME
}


/*
 * ======================
 * PUSH AND POP FUNCTIONS
 * ======================
 */

// Adds item to front of the list
template <typename TData>
void SingleLinkedList<TData>::push_front(const TData& item) {
    // FIXME
}

// Adds item to back of the list
template <typename TData>
void SingleLinkedList<TData>::push_back(const TData& item) {
    // FIXME
}

// Removes first item in the list
template <typename TData>
void SingleLinkedList<TData>::pop_front() {
    if (pHead == nullptr) {
        throw std::invalid_argument("Attempt to call pop_front() on an empty list");
    }

    Node<TData>*
}

// Remove last item in the list
template <typename TData>
void SingleLinkedList<TData>::pop_back() {
    // FIXME
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
    // FIXME
}

// Removes item at specified index and returns true if successful
template <typename TData>
bool SingleLinkedList<TData>::remove(size_t index) {
    // FIXME
}

// Returns the index of the first occurrence of the item or returns the size of the list if not found
template <typename TData>
size_t SingleLinkedList<TData>::find(const TData& item) const {
    // FIXME
}
