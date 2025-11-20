#ifndef FASTSORT_H
#define FASTSORT_H

#include <iostream>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
//SHELL SORT
int shellComparisons = 0, shellSwaps = 0;
 
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                shellComparisons++;
                arr[j] = arr[j - gap];
                shellSwaps++;
            }
            arr[j] = temp;
        }
    }
}
//MERGE SORT
int mergeComparisons = 0;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++){
		L[i] = arr[left + i];
	}
    for (int j = 0; j < n2; j++){
		R[j] = arr[mid + 1 + j];
	}

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
    	mergeComparisons++;
        if (L[i] <= R[j]){
			arr[k++] = L[i++];
        }else {
		arr[k++] = R[j++];
		}
    }
    while (i < n1) {
		arr[k++] = L[i++];
	}
    while(j < n2){
		arr[k++] = R[j++];
	}
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//QUICK SORT
int quickComparisons = 0, quickSwaps = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    quickSwaps++;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickComparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);  
        quickSort(arr, pivotIndex + 1, high); 
    }
}
#endif
