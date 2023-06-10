#include <iostream>

// Function that takes an array reference as a parameter
void printArray(int (&arr)[5]) {
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    // Call the function and pass the array by reference
    printArray(arr);

    return 0;
}