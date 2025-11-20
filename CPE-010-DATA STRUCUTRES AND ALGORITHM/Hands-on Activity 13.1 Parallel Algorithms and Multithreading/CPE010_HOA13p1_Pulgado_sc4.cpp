#include <iostream>
#include <vector>
#include <thread>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;

    std::thread t1([&]() { mergeSort(arr, left, mid); });
    std::thread t2([&]() { mergeSort(arr, mid + 1, right); });

    t1.join();
    t2.join();

    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {8, 3, 7, 4, 2, 9, 5, 1};

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int n : arr) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
