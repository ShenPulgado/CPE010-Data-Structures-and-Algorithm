#ifndef SORTING_H
#define SORTING_H

#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1); 
}

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

void shellSort(int arr[], int low, int high) {
    int size = high - low + 1;

    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = low + gap; i <= high; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= low + gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void quickPartitionWithOtherSorts(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        mergeSort(arr, low, pivotIndex - 1);

    	shellSort(arr, pivotIndex + 1, high);
    }
}

#endif

