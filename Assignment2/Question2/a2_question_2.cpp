#include "stack.h"

#include <iostream>

using namespace std;

int main() {
    // Create integer stack
    Stack stack;

    // Test isEmpty
    cout << "Testing isEmpty:" << endl;
    cout << "LIST IS: ";
    if (!stack.isEmpty()) {
        cout << "not ";
    }
    cout << "empty" << endl << endl;

    // Testing push
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout << "STACK EXPECTED: 1 2 3 4 5\n";
    cout << "STACK ACTUAL: ";
    stack.printStack();
    cout << endl;

    // Testing pop
    stack.pop();
    cout << "STACK EXPECTED: 1 2 3 4\n";
    cout << "STACK ACTUAL: ";
    stack.printStack();
    cout << endl;

    // Testing top
    cout << "TOP EXPECTED: 5\n";
    cout << "TOP ACTUAL: " << stack.top() << endl << endl;

    // Testing average
    cout << "AVERAGE EXPECTED: 2.5\n";
    cout << "AVERAGE ACTUAL: " << stack.average() << endl << endl;

    // Testing edge cases
    cout << "Emptying stack and testing edge cases:" << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    try {
        stack.pop();
    } catch (const std::out_of_range& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    try {
        stack.top();
    } catch (const std::out_of_range& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    try {
        stack.average();
    } catch (const std::out_of_range& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    return 0;
}