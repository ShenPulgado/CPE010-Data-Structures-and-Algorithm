#include <iostream>
#include "sorting.h"

int main() {
    const int size = 10;
    int arr[size] = {29, 10, 14, 37, 13, 25, 5, 30, 18, 7};

    std::cout << "Original array:\n";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    quickPartitionWithOtherSorts(arr, 0, size - 1);

    std::cout << "\nArray after sorting with Partition + (Merge Sort on left, Shell Sort on right):\n";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}

