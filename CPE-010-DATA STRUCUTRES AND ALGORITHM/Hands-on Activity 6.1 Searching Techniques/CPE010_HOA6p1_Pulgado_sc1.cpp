#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searching.h"
#include "node.h"

int main() {
    //create linked list for linear search
    Node<char> *name1 = new_node('C');
    Node<char> *name2 = new_node('R');
    Node<char> *name3 = new_node('I');
    Node<char> *name4 = new_node('S');
    Node<char> *name5 = new_node('H');
    Node<char> *name6 = new_node('E');
    Node<char> *name7 = new_node('N');
    
    //linked them together
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = NULL;
    
    linearLS(name1, 'S');
    
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    binarySearch(arr, size, 7);  
    binarySearch(arr, size, 8); 
    
    char choice = 'y';
    int count = 1;
    int newData;
    Node<int> *temp, *head, *node;
    
    while(choice=='y'){
    	std::cout << "Enter data: ";
    	std::cin >> newData;
    	
    	if(count == 1){
    		head = new_node(newData);
    		std::cout << "Succesfully added" << head->data << "to the list.\n";
    		count++;
    		
		} else if(count==2){
			node = new_node(newData);
			head->next = node;
			node->next = NULL;
			std::cout << "Succesfully added" << node->data << "to the list. \n";
			count++;
			
		}else {
			temp = head;
			while(true){
				if(temp->next == NULL) break;
				temp = temp->next;
			} node = new_node(newData);
			temp->next = node;
			std::cout << "Successfully added" << node->data << "to the list. \n";
			count++;
		}
		std::cout << "Continue (y/n): ";
		std::cin>> choice;
	}
	
	std::cout << "Final linked list: ";
    Node<int>* currNode = head;
    while (currNode != NULL) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;


    int key;
    std::cout << "Enter value to search: ";
    std::cin >> key;

    Node<int>* result = binarySearchLL(head, key);
    if (result != NULL) {
        std::cout << "Found " << key << " in the list." << std::endl;
    } else {
        std::cout << key << " not found in the list." << std::endl;
    }
    



    return 0;
}

