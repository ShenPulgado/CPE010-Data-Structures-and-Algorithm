#include <iostream>

int sumNumbers(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) { 
        sum += arr[i];               
    }
    return sum;
}


int main() {
    int numbers[] = {1,2,3,4,5,6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "The sum is: " << sumNumbers(numbers, size) << "\n";
}

