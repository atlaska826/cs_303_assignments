#include "assignment_1.h"
#include <iostream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open(".../A1input.txt");
    if (!inFile.is_open()) {
        cout << "Could not open input file!" << endl;
        return 0;
    }

    return 0;
}

int findNum(int *arr, size_t size, int num) {
    return 0;
}