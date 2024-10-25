#ifndef CS_303_ASSIGNMENTS_QUEUE_H
#define CS_303_ASSIGNMENTS_QUEUE_H

#include <cstddef>

template <typename TData>
struct Node {
    TData data;
    Node* pNext;

    Node(const TData& dataValue, Node* nextNode) : data(dataValue), pNext(nextNode) {};
};

template <typename TData>
class Queue {
public:
    // Constructor and Destructor
    Queue();
    ~Queue();

    // Push and Pop Functions
    void push(const TData& item);
    void pop();

    // Utility Functions
    TData& front();
    bool empty() const;
    size_t size() const;
    void moveToRear();
    void printQueue() const;

private:
    Node<TData>* pFront;
    Node<TData>* pBack;
    size_t num_items;
};

#include "queue.tpp"

#endif
