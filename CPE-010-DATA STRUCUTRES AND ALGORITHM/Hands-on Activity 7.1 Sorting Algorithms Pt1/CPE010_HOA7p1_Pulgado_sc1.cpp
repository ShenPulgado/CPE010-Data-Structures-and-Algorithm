#include <iostream>
#include <cstdlib>  
#include "sorts.h"


int main() {
    const int SIZE = 100;
    int arr[SIZE];

    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 100 + 1; 
    }

    std::cout << "Unsorted Array: " << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
	
	bubbleSort(arr, SIZE);
	std::cout << "Sorted Array (Bubble):\n";
	for (int i = 0; i < SIZE; i++){
		std::cout << arr[i] << " ";
	}
    std::cout << std::endl;
    
    
    selectionSort(arr, SIZE);
    std::cout << "Sorted array (Selection):\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
    
    insertionSort(arr,SIZE);
    std::cout << "Sorted array (insertion sort):\n";
	for (int i=0; i<SIZE;i++){
		std::cout << arr[i] <<" ";
	}
	std::cout << "\n";

    return 0;
}
