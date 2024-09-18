#include "stack.h"

#include <iostream>
#include <stdexcept>
#include <numeric>

using namespace std;

// Constructor
Stack::Stack() {}

/*
 * =================
 * UTILITY FUNCTIONS
 * =================
 */

// Checks if the stack is empty or not
bool Stack::isEmpty() const {
    return stackVector.empty();
}

// Adds an item to the stack
void Stack::push(const int& value) {
    stackVector.push_back(value);
}

// Removes an item from the stack
void Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Attempt to call pop() on an empty stack");
    }
    stackVector.pop_back();
}

void Stack::printStack() const {
    for (const int& num : stackVector) {
        cout << num << " ";
    }
    cout << endl;
}

/*
 * ================
 * ACCESS FUNCTIONS
 * ================
 */

// Returns the value on the top of the stack
int Stack::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Attempt to call top() on an empty stack");
    }
    return stackVector.back();
}

// Find the average value of the stack elements
double Stack::average() const {
    if (isEmpty()) {
        throw std::out_of_range("Attempt to call average() on an empty stack");
    }

    // Source of below accumulate method: https://www.tutorialspoint.com/how-to-sum-up-elements-of-a-cplusplus-vector
    // I would have used the standard for loop method for the sum, but I saw this and decided to try it out
    return accumulate(stackVector.begin(), stackVector.end(), 0.0) / stackVector.size();
}