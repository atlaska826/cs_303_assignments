#include "a3_question_3.h"

#include <iostream>

using namespace std;

int main() {
    list<int> myList = {5, 3, 6, 10, 49, 2, 4, 90, 20, 8, 73};

    cout << "Unsorted List: ";
    for (int& i : myList) {
        cout << i << " ";
    }
    cout << endl;

    insertion_sort(myList);

    cout << "Sorted List: ";
    for (int& i : myList) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

void insertion_sort(std::list<int>& nums) {
    int key;
    list<int>::iterator insertPoint;

    // Starts for loop from the second element as the first one is already "sorted"
    for (auto itr = next(nums.begin()); itr != nums.end(); ++itr) {
        key = *itr; // Element to be inserted
        insertPoint = itr; // Iterator to find the insertion point

        // Moves larger elements to the right while moving insertion point to the left
        while (insertPoint != nums.begin() && *prev(insertPoint) > key) {
            *insertPoint = *prev(insertPoint);
            --insertPoint;
        }

        *insertPoint = key; // Put the element to insert at the correct location in the list
    }
}
