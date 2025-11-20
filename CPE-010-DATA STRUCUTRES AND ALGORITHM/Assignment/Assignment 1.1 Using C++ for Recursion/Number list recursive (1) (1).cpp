#include <iostream>

int sumNumbers(int arr[], int size) {
    if (size == 1) return arr[0];
    return arr[size - 1] + sumNumbers(arr, size - 1);
}


int main() {
    int numbers[] = {1,2,3,4,5,6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "The sum is: " << sumNumbers(numbers, size) << "\n";
    
}

