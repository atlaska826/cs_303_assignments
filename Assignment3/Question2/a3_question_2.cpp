#include "a3_question_2.h"

#include <iostream>

using namespace std;

int main() {
    vector<int> myVector = {5, 3, 6, 10, 49, 2, 4, 6, 90, 20, 6, 8, 73};
    int target = 55;

    // Run linear search and output result
    size_t searchResult = linear_search_last(myVector, target, myVector.size());
    if (searchResult == -1) {
        cout << "Target number " << target << " not found." << endl;
    } else {
        cout << "Last occurence of target number " << target << " found at index " << searchResult << "." << endl;
    }
    return 0;
}

// Linear search function
size_t linear_search_last(vector<int>& nums, int& target, size_t pos_last) {
    if (pos_last == -1) { // Number not found
        return -1;
    }
    if (target == nums[pos_last]) { // Number is found
        return pos_last;
    }
    else { // Number not found, but still have more to search
        return linear_search_last(nums, target, pos_last - 1);
    }
}