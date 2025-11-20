#include <iostream>
#include "fastsort.h"

int main() {
    const int SIZE = 15;
    int arr[SIZE] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    std::cout << "Original Array:" << std::endl;
    printArray(arr, SIZE);

    int quickArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        quickArr[i] = arr[i];
    }

    quickSort(quickArr, 0, SIZE - 1);

    std::cout << "\nSorted Array (Quick Sort):" << std::endl;
    printArray(quickArr, SIZE);
    std::cout << "Quick Sort Comparisons: " << quickComparisons << std::endl;
    std::cout << "Quick Sort Swaps: " << quickSwaps << std::endl;

    int mergeArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        mergeArr[i] = arr[i];
    }

    mergeSort(mergeArr, 0, SIZE - 1);

    std::cout << "\nSorted Array (Merge Sort):" << std::endl;
    printArray(mergeArr, SIZE);
    std::cout << "Merge Sort Comparisons: " << mergeComparisons << std::endl;

    int shellArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        shellArr[i] = arr[i];
    }

    shellSort(shellArr, SIZE);

    std::cout << "\nSorted Array (Shell Sort):" << std::endl;
    printArray(shellArr, SIZE);
    std::cout << "Shell Sort Comparisons: " << shellComparisons << std::endl;
    std::cout << "Shell Sort Swaps: " << shellSwaps << std::endl;

    return 0;
}

