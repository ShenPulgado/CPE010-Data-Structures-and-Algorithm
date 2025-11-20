#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "sort2.h" 

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 100 + 1;
    }

    std::cout << "Original Array:" << std::endl;
    printArray(arr, SIZE);

    int totalSwaps = shellSort(arr, SIZE);

    std::cout << "\nFinal Sorted Array (Shell Sort):" << std::endl;
    printArray(arr, SIZE);

    std::cout << "\nTotal swaps performed: " << totalSwaps << std::endl;
	//merge sort
	std::cout << "\n=== Merge Sort ===" << std::endl;

    divisions = 0;
    conquers = 0;

    mergeSort(arr, 0, SIZE - 1);

    std::cout << "Final Sorted Array (Merge Sort):" << std::endl;
    printArray(arr, SIZE);

    std::cout << "Total divisions: " << divisions << std::endl;
    std::cout << "Total conquers (merges): " << conquers << std::endl;
    
    //quick sort
    std::cout << "\n=== Quick Sort ===" << std::endl;
    quickComparisons = 0;
    quickSort(arr, 0, SIZE - 1);
    std::cout << "Final Sorted Array (Quick Sort):" << std::endl;
    printArray(arr, SIZE);
    std::cout << "Total comparisons (Quick Sort): " << quickComparisons << std::endl;

    return 0;
}

