#include "single_linked_list.h"

#include <iostream>

using namespace std;

int main() {
    // Create list of integers
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

    // Test find
    cout << "Testing find:" << endl;
    cout << "INDEX EXPECTED FOR 3: 2\n";
    cout << "INDEX ACTUAL FOR 3: " << list.find(3) << endl;
    cout << "INDEX EXPECTED FOR 10 (not found): 4\n";
    cout << "INDEX ACTUAL FOR 10 (not found): " << list.find(10) << endl << endl;

    // Test front and back
    cout << "Testing front and back:" << endl;
    cout << "FRONT EXPECTED: 2\n";
    cout << "FRONT ACTUAL: " << list.front() << endl;
    cout << "BACK EXPECTED: 4\n";
    cout << "BACK ACTUAL: " << list.back() << endl << endl;

    // Test insert at good index
    cout << "Testing good insert at index 2:" << endl;
    list.insert(2, 5);
    cout << "LIST EXPECTED: 2 1 5 3 4\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test insert at bad index
    cout << "Testing bad insert at index 90:" << endl;
    list.insert(90, 6);
    cout << "LIST EXPECTED: 2 1 5 3 4 6\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test remove
    cout << "Testing remove at index 1:" << endl;
    list.remove(1);
    cout << "LIST EXPECTED: 2 5 3 4 6\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test pop_front
    cout << "Testing pop_front:" << endl;
    list.pop_front();
    cout << "LIST EXPECTED: 5 3 4 6\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Test pop_back
    cout << "Testing pop_back:" << endl;
    list.pop_back();
    cout << "LIST EXPECTED: 5 3 4\n";
    cout << "LIST ACTUAL: ";
    list.printList();
    cout << endl;

    // Empty list to test edge cases
    cout << "Emptying list:" << endl;
    list.pop_back();
    list.pop_front();
    list.remove(0);
    cout << "LIST IS: ";
    if (!list.empty()) {
        cout << "not ";
    }
    cout << "empty" << endl << endl;

    // Testing edge cases
    cout << "Testing edge cases:" << endl;
    try {
        list.pop_back();
    } catch (const std::invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    try {
        list.pop_front();
    } catch (const std::invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    try {
        list.front();
    } catch (const std::out_of_range& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    try {
        list.back();
    } catch (const std::out_of_range& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    return 0;
}
