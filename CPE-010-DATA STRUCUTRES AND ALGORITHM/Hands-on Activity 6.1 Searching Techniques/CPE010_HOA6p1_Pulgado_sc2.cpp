#include <iostream>
#include "searching.h"  

int main() {
    int arry[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int n = sizeof(arry) / sizeof(arry[0]);  

    int key = 18;

    
    int compsArr = sequentialSearchComparisons(arry, n, key);
    std::cout << "Array: Found key " << key 
              << " after " << compsArr << " comparisons.\n";

    
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    for (int i = 0; i < n; i++) {
        Node<int>* node = new_node(arry[i]);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    
    int compsLL = linearLSComparisons(head, key);
    std::cout << "Linked List: Found key " << key 
              << " after " << compsLL << " comparisons.\n";
              
    int compsLL = linearLSComparisons(head, key);
    std::cout << "Linked List: Found key " << key 
              << " after " << compsLL << " comparisons.\n";

    return 0;
}

