#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "node.h"

template <typename T>
void linearLS(Node<T> *head, T dataFind) {
    Node<T>* current = head;  
    int position = 0;     


    while (current != NULL) {
        if (current->data == dataFind) {
            std::cout << "Searching is successful. Found " 
                      << dataFind 
                      << " at position " << position 
                      << std::endl;
            return;
        }
        current = current->next;
        position++;
    }

    std::cout << "Searching is unsuccessful. " 
              << dataFind 
              << " not found in the list." 
              << std::endl;
}

template <typename T>
int binarySearch(T arr[], int n, T key) {
    int low = 0;        
    int up = n - 1;    
    
    while (low <= up) {
        int mid = (low + up) / 2; 

        if (key == arr[mid]) {
            std::cout << "Search element " << key 
                      << " is found at index " << mid << std::endl;
            return mid;
        }
        else if (key < arr[mid]) {
            up = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }

    std::cout << "Search element " << key << " is not found." << std::endl;
    return -1;
}
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end) {
    if (start == NULL) return NULL;

    Node<T>* slow = start;
    Node<T>* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

template <typename T>
Node<T>* binarySearchLL(Node<T>* head, T key) {
    Node<T>* start = head;
    Node<T>* end = NULL;

    do {
        Node<T>* mid = getMiddle(start, end);
        if (mid == NULL) return NULL;

        if (mid->data == key) {
            return mid;
        }
        else if (mid->data < key) {
            start = mid->next;
        }
        else {
            end = mid;
        }
    } while (end == NULL || end != start);

    return NULL;
}

int sequentialSearchComparisons(int arry[], int n, int key) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arry[i] == key) {
            return comparisons;
        }
    }
    return comparisons; 
}

// === Sequential search for linked list: counts comparisons until first match ===
template <typename T>
int linearLSComparisons(Node<T>* head, T dataFind) {
    Node<T>* current = head;
    int comparisons = 0;

    while (current != NULL) {
        comparisons++;
        if (current->data == dataFind) {
            return comparisons; // stop at first match
        }
        current = current->next;
    }
    return comparisons; // searched whole list
}

#endif
