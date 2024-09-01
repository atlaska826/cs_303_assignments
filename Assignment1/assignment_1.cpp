#include "assignment_1.h"
#include <iostream>

using namespace std;

int main() {
    // TODO: Check if you can update working directory with CMakeLists.txt
    ifstream inFile;
    inFile.open("./A1input.txt");
    if (!inFile) {
        cout << "Could not open input file!" << endl;
        return 0;
    }

    // TODO: Initialize array with file

    inFile.close();

    int nums[] ={5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6};
    int userChoice;

    while (true) {
        printMenu();
        cout << "Please enter your menu choice: ";

        while (true) {
            if (!(cin >> userChoice)) {
                cout << "ERROR: You must enter a number.\n";
            } else if (userChoice > 5 || userChoice < 1) {
                cout << "ERROR: That is not a valid menu option.\n";
            } else {
                clearInput();
                break;
            }
            clearInput();
            cout << "\nPlease enter your menu choice: ";
        }

        if (userChoice == 5) { // End program
            return 0;
        } else if (userChoice == 1) { // Find num
            int searchNum;

            while (true) {
                cout << "\nPlease enter the number you wish to find: ";

                if (!(cin >> searchNum)) {
                    cout << "ERROR: You must enter a number.\n";
                    clearInput();
                } else {
                    clearInput();
                    break;
                }
            }

            size_t foundIndex = findNum(nums, 12, searchNum);
            if (foundIndex == -1) {
                cout << "Could not find the number " << searchNum << " in the array.\n\n";
            } else {
                cout << "Located the number " << searchNum << " at index " << foundIndex << ".\n\n";
            }
        } else if (userChoice == 2) { // Change value
            // TODO: User input for index and integer
            changeArrVal(nums, 12, 0, 6);
        } else if (userChoice == 3) { // Add value
            // TODO: User input for integer
            addVal(nums, 12, 6);
        } else { // Remove value
            // TODO: User input for index
            removeVal(nums, 12, 6);
        }
    }
}

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

// Prints out the array
void printArr(const int arr[], size_t size) {
    cout << left << setw(11) << "Index" << " " << "Number" << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(11) << i << " " << arr[i] << endl;
    }
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
void changeArrVal(int arr[], size_t size, size_t index, int newVal) {
    int oldVal = arr[index];
    arr[index] = newVal;
    cout << "\nChanged number at index " << index << " from " << oldVal << " to " << newVal << ".\n\n";
}

// TODO: Add value to array
void addVal(int arr[], size_t size, int newVal) {
    // Code
}

// TODO: Remove array value based on index
void removeVal(int arr[], size_t size, size_t index) {
    // Code
}