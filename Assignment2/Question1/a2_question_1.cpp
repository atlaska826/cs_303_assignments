#include "single_linked_list.h"

#include <iostream>

using namespace std;

void testLinkedList() {
    SingleLinkedList<int> list;

    // Test push_front
    cout << "Testing push_front and push_back:" << endl;
    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    list.push_back(4);

    cout << "LIST EXPECTED: 2 1 3 4\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test insert
    cout << "Testing insert at index 2:" << endl;
    list.insert(2, 5);

    cout << "LIST EXPECTED: 2 1 5 3 4\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test remove
    cout << "Testing remove at index 1:" << endl;
    list.remove(1);

    cout << "LIST EXPECTED: 2 5 3 4\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test pop_front
    cout << "Testing pop_front:" << endl;
    list.pop_front();

    cout << "LIST EXPECTED: 5 3 4\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test pop_back
    cout << "Testing pop_back:" << endl;
    list.pop_back();

    cout << "LIST EXPECTED: 5 3 \n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test edge case of empty list
    cout << "Emptying list and testing edge cases:" << endl;
    list.pop_back();
    list.pop_front();

    // Attempting to pop from an empty list should handle gracefully
    try {
        list.pop_back();
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}

int main() {
    testLinkedList();
    return 0;
}
