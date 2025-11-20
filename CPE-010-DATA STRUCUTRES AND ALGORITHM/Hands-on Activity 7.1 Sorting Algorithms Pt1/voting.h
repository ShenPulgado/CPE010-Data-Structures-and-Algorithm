#ifndef VOTING_H
#define VOTING_H
#include <cstddef>
#include <utility>
#include <iostream>
template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void countVotes(const int arr[], int size, int counts[], int candidateCount) {

    for (int i = 0; i < candidateCount; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 1 && arr[i] <= candidateCount) {
            counts[arr[i] - 1]++; 
        }
    }
}
int findWinner(const int counts[], int candidateCount) {
    int maxIndex = 0;
    for (int i = 1; i < candidateCount; i++) {
        if (counts[i] > counts[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex; 
}
#endif

