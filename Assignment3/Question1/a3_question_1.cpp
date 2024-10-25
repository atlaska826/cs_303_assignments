#include "queue.h"

#include <iostream>

using namespace std;

int main() {
    // Create a Queue of integers
    Queue<int> queue;

    // Test push_front
    cout << "Testing push:" << endl;
    queue.push(2);
    queue.push(82);
    queue.push(36);
    queue.push(27);
    queue.push(69);
    queue.push(42);
    queue.push(93);
    queue.push(19);
    queue.push(33);
    queue.push(16);
    cout << "QUEUE EXPECTED: 2 82 36 27 69 41 93 19 33 16\n";
    cout << "QUEUE ACTUAL: ";
    queue.printQueue();
    cout << endl;

    // Testing pop
    cout << "Testing push:" << endl;
    queue.pop();
    cout << "QUEUE EXPECTED: 82 36 27 69 41 93 19 33 16\n";
    cout << "QUEUE ACTUAL: ";
    queue.printQueue();
    cout << endl;

    // Testing front
    cout << "Testing front:" << endl;
    cout << "VALUE EXPECTED: 82\n";
    cout << "VALUE ACTUAL: " << queue.front() << endl;
    cout << endl;

    // Testing size
    cout << "Testing size:" << endl;
    cout << "VALUE EXPECTED: 9\n";
    cout << "VALUE ACTUAL: " << queue.size() << endl;
    cout << endl;

    // Testing empty
    cout << "Testing empty:" << endl;
    cout << "VALUE EXPECTED: 0\n";
    cout << "VALUE ACTUAL: " << queue.empty() << endl;
    cout << endl;

    // Testing moveToRear
    cout << "Testing moveToRear:" << endl;
    queue.moveToRear();
    cout << "QUEUE EXPECTED: 36 27 69 41 93 19 33 16 82\n";
    cout << "QUEUE ACTUAL: ";
    queue.printQueue();
}