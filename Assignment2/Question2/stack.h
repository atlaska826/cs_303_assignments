#ifndef CS_303_ASSIGNMENTS_STACK_H
#define CS_303_ASSIGNMENTS_STACK_H

#include <vector>

using namespace std;

class Stack {
public:
    // Constructor
    Stack();

    // Utility Functions
    bool isEmpty() const;
    void push(const int& value);
    void pop();

    // Access Functions
    int top() const;
    double average() const;

private:
    vector<int> stackVector;
};

#endif
