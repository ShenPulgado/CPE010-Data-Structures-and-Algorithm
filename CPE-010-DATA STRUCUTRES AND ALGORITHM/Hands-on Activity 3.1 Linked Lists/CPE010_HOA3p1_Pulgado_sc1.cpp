#include <iostream>
#include <utility>

class Node {
public:
    char data;
    Node *next;
};

void ListTraversal(Node* n) {
    while (n != nullptr) {            
        std::cout << n->data << " ";   
        n = n->next;                   
    }
    std::cout << std::endl;            
}

int main() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    last = new Node();

   
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '1';
    fourth->next = fifth;

    fifth->data = '0';
    fifth->next = last;

    last->data = '1';
    last->next = nullptr;

    Node *newNode = new Node();  
    newNode->data = 'G';         
    newNode->next = head;        
    head = newNode;
    
    Node* previous = head;
    while (previous != nullptr && previous->data != 'P') {
        previous = previous->next;
    }
    
    if (previous == nullptr) {
        std::cout << "Previous node cannot be null." << std::endl;
    } else {
      Node* newNode = new Node();
      newNode->data = 'E';
      newNode->next = previous->next;
      previous->next = newNode;
    }
    ListTraversal(head);

    return 0;
}
