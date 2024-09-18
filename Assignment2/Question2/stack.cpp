#include "stack.h"

#include <numeric>

using namespace std;

// TODO: Add error handling

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
    stackVector.pop_back();
}

/*
 * ================
 * ACCESS FUNCTIONS
 * ================
 */

// Returns the value on the top of the stack
int Stack::top() const {
    return stackVector.back();
}

// Find the average value of the stack elements
double Stack::average() const {
    // Source of below accumulate method: https://www.tutorialspoint.com/how-to-sum-up-elements-of-a-cplusplus-vector
    // I would have used the standard for loop method for the sum, but I saw this and decided to try it out
    return accumulate(stackVector.begin(), stackVector.end(), 0.0) / stackVector.size();
}