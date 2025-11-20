#include <iostream>

class Node {
public:
    int data;   
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private:
    Node* frontPtr;
    Node* backPtr; 

public:
    Queue() : frontPtr(NULL), backPtr(NULL) {}

    void display() {
        if (frontPtr == NULL) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* temp = frontPtr;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void insertNonEmpty(int value) {
        Node* newPtr = new Node(value);
        newPtr->next = NULL;            
        backPtr->next = newPtr;         
        backPtr = newPtr;               
        std::cout << "Inserted " << value << " into a non-empty queue.\n";
        display();
    }

    void insertEmpty(int value) {
        Node* newPtr = new Node(value);
        frontPtr = newPtr;              
        backPtr = newPtr;              
        std::cout << "Inserted " << value << " into an empty queue.\n";
        display();
    }

    void deleteMultiple() {
        if (frontPtr == NULL || frontPtr->next == NULL) {
            std::cout << "Operation invalid: not enough items.\n";
            return;
        }
        Node* tempPtr = frontPtr;      
        frontPtr = frontPtr->next;     
        tempPtr->next = NULL;         
        std::cout << "Deleted " << tempPtr->data << " from queue with multiple items.\n";
        delete tempPtr;                
        display();
    }

    void deleteSingle() {
        if (frontPtr == NULL || frontPtr->next != NULL) {
            std::cout << "Operation invalid: queue does not have exactly one item.\n";
            return;
        }
        Node* tempPtr = frontPtr;      
        frontPtr = NULL;                
        backPtr = NULL;                
        std::cout << "Deleted " << tempPtr->data << " from queue with one item.\n";
        delete tempPtr;               
        display();
    }
};

int main() {
    Queue q;

    q.insertEmpty(2);

    q.insertNonEmpty(4);
    q.insertNonEmpty(1);
    q.insertNonEmpty(7);
    q.insertNonEmpty(3);

    q.deleteMultiple();

    q.deleteMultiple(); 
    q.deleteMultiple(); 
    q.deleteMultiple(); 

    q.deleteSingle();   

    return 0;
}

