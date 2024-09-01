#ifndef CS_303_ASSIGNMENTS_ASSIGNMENT_1_H
#define CS_303_ASSIGNMENTS_ASSIGNMENT_1_H

#include <fstream>
#include <iomanip>

// Clears the input
void clearInput();

// Prints the menu choices
void printMenu();

// Prints out the array
void printArr(const int arr[], size_t size);

// Resizes the array and clears up memory from the old one
void resizeArr(int*& arr, size_t& capacity);

// Check if a certain integer exists in the array
size_t findNum(const int arr[], size_t size, int num);

// Change array value
void changeArrVal(int arr[], size_t size, size_t index, int changeVal);

// Add value to array
void addVal(int*& arr, size_t& size, size_t& capacity, int newVal);

// Remove array value based on index
void removeVal(int arr[], size_t& size, size_t index);

#endif
