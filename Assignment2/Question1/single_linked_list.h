#ifndef CS_303_ASSIGNMENTS_SINGLE_LINKED_LIST_H
#define CS_303_ASSIGNMENTS_SINGLE_LINKED_LIST_H

#include <cstddef>

template <typename TData>
struct Node {
    TData data;
    Node* pNext;

    Node(const TData& dataValue, Node* nextNode) : data(dataValue), pNext(nextNode) {};
};

template <typename TData>
class SingleLinkedList {
public:
    // Constructor and Destructor
    SingleLinkedList();
    ~SingleLinkedList();

    // Push and Pop Functions
    void push_front(const TData& item);
    void push_back(const TData& item);
    void pop_front();
    void pop_back();

    // Access Functions
    TData& front();
    TData& back();

    // Utility Functions
    bool empty() const;
    void insert(size_t index, const TData& item);
    bool remove(size_t index);
    size_t find(const TData& item) const;
    void printList() const;

private:
    Node<TData>* pHead;
    Node<TData>* pTail;
    size_t num_items;
};

#include "single_linked_list.tpp"

#endif
