#include "assignment_1.h"

#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    // Open array file
    ifstream inFile;
    inFile.open("./A1input.txt");
    if (!inFile.is_open()) {
        cout << "ERROR: Could not open input file! Please check that your working directory is set to Assignment1 directory.";
        return 0;
    }

    // Initialize array with file
    const size_t INITIAL_SIZE = 10;
    int* nums = new int[INITIAL_SIZE];
    size_t capacity = INITIAL_SIZE; // How many items the array can hold
    size_t numItems = 0; // How many items the array currently has

    // Load array with
    int value;
    while (true) {
        if (!(inFile >> value)) {
            inFile.clear();
            inFile.ignore();
            if (inFile.eof()) { // End of file reached
                inFile.close();
                break;
            }
            continue;
        }

        if (numItems == capacity) { // Update the size of the array if necessary
            resizeArr(nums, capacity);
        }
        nums[numItems++] = value;
    }

    // FIXME: Print start array
    printArr(nums, numItems);

    // Performs menu functions based on user input until the user inputs the stop value
    int userChoice;
    while (true) {
        // Get menu operation from user
        printMenu();
        while (true) {
            cout << "Please enter your menu choice: ";
            if (!(cin >> userChoice)) {
                cout << "ERROR: You must enter a number.\n\n";
            } else if (userChoice > 5 || userChoice < 1) {
                cout << "ERROR: That is not a valid menu option.\n\n";
            } else {
                clearInput();
                break;
            }
            clearInput();
        }


        // Perform action based on selected menu operation
        if (userChoice == 5) { // End program
            // FIXME: Print end array
            printArr(nums, numItems);
            delete[] nums;
            return 0;
        } else if (userChoice == 1) { // Find number
            int searchNum = getInt("Please enter the number you wish to find: ");
            size_t foundIndex = findNum(nums, numItems, searchNum);
            if (foundIndex == -1) {
                cout << "Could not find the number " << searchNum << " in the array.\n\n";
            } else {
                cout << "Located the number " << searchNum << " at index " << foundIndex << ".\n\n";
            }
        } else if (userChoice == 2) { // Change value
            changeArrVal(nums,
                         getIndex("Please enter the index of the value you wish to change: "),
                         getInt("Please enter the new number: ")
            );
        } else if (userChoice == 3) { // Add value
            addVal(nums, numItems, capacity,
                   getInt("Please enter the number you wish to add: ")
            );
        } else { // Remove value
            removeVal(nums, numItems,
                      getIndex("Please enter the index of the value you wish to remove: ")
            );
        }
    }
}

/*
 * ====================
 * USER INPUT FUNCTIONS
 * ====================
 */

// Clears the input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prints the menu choices
void printMenu() {
    cout << "------------------------------------\n";
    cout << setw(14) << "" << "COMMANDS\n";
    cout << "1. Check if number exists\n";
    cout << "2. Modify value of a specific number\n";
    cout << "3. Add number to end of array\n";
    cout << "4. Remove number from array\n";
    cout << "5. End program\n";
    cout << "------------------------------------\n";
}

// Get integer from input
int getInt(const string& prompt) { // FIXME: Finish function
    int input;
    while (true) {
        try {
            cout << "\n" << prompt;
            cin >> input;

            clearInput();
            return input;
        }
        catch (ios_base::failure& iof) {
            cout << "ERROR: You must enter a number.\n";

            clearInput();
            return 6;
        }
    }
}

// Get index from input
size_t getIndex(const string& prompt) { // FIXME: Finish function
    size_t input;
    while(true) {
        try {
            cout << "\n" << prompt;
            cin >> input;

            clearInput();
            return input;
        }
        catch (...) {
            cout << "ERROR\n";

            clearInput();
            return 6;
        }
    }
}

/*
 * =========================
 * ARRAY OPERATION FUNCTIONS
 * =========================
 */

// Prints out the array
void printArr(const int arr[], size_t size) {
    cout << "------------------\n";
    cout << left << setw(11) << "Index" << " " << "Number" << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(11) << i << " " << arr[i] << endl;
    }
    cout << endl;
}

// Resizes the array and clears up memory from the old one
void resizeArr(int*& arr, size_t & capacity) {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (size_t i = 0; i < capacity / 2; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

// Check if a certain integer exists in the array and returns index
size_t findNum(const int arr[], size_t size, int num) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

// Change array value
void changeArrVal(int arr[], size_t index, int newVal) {
    int oldVal = arr[index];
    arr[index] = newVal;
    cout << "Changed number at index " << index << " from " << oldVal << " to " << newVal << ".\n\n";
}

// Add value to array
void addVal(int*& arr, size_t& size, size_t& capacity, int newVal) {
    if (size == capacity) {
        resizeArr(arr, capacity);
    }
    arr[size++] = newVal;
    cout << "Added the number " << newVal << " to the array.\n\n";
}

// Remove array value based on index
void removeVal(int arr[], size_t& size, size_t index) {
    // Iterates through the array starting at the value to remove and shifts all the values left
    for (size_t i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[--size] = 0; // Decrease size and set the final element to 0
    cout << "Removed the number at index " << index << " from the array.\n\n";
}