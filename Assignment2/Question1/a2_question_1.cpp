#include "single_linked_list.h"

#include <iostream>

using namespace std;

void testLinkedList() {
    SingleLinkedList<int> list;  // Create a linked list for integers

    // Test push_front
    cout << "Testing push_front and push_back:" << endl;
    list.push_front(1);  // List: 1
    list.push_front(2);  // List: 2 -> 1
    list.push_back(3);   // List: 2 -> 1 -> 3
    list.push_back(4);   // List: 2 -> 1 -> 3 -> 4

    // Print list
    cout << "List after pushes: ";
    list.printList();

    // Test insert
    cout << "Testing insert at index 2:" << endl;
    list.insert(2, 5);  // List: 2 -> 1 -> 5 -> 3 -> 4

    // Print list
    cout << "List after insertion: ";
    list.printList();

    // Test remove
    cout << "Testing remove at index 1:" << endl;
    list.remove(1);  // List: 2 -> 5 -> 3 -> 4

    // Print list
    cout << "List after removal: ";
    list.printList();

    // Test pop_front
    cout << "Testing pop_front:" << endl;
    list.pop_front();  // List: 5 -> 3 -> 4

    // Print list
    cout << "List after pop_front: ";
    list.printList();

    // Test pop_back
    cout << "Testing pop_back:" << endl;
    list.pop_back();   // List: 5 -> 3

    // Print list
    cout << "List after pop_back: ";
    list.printList();

    // Test edge case of empty list
    cout << "Testing edge case on empty list:" << endl;
    list.pop_back();   // List: 5 (only element)
    list.pop_front();  // List: empty

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
