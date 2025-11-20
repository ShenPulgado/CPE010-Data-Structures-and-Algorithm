#include <iostream>
 class Node {
    public:
    int data;
    Node *next;
 };

 Node *head=NULL, *tail=NULL;
 
 void push(int newData){
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = NULL;

    if (head==NULL) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
 }
 int pop(){
    int tempVal;
    Node *temp;
    if(head == NULL){
        head = tail = NULL;
        std::cout << "Stack Underflow." << std::endl;
        return -1;
    }
    else {
        temp = head;
        tempVal = temp->data;
        head = head->next;
        delete (temp);
        return tempVal;
    }
 }
 void Top(){
    if(head == NULL){
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    else {
        std::cout << "Top os Stack: " << head->data << std::endl;
    }
 }
void display(){
    if(head == NULL){
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    Node* temp = head;
    std::cout << "Stack elements (top to bottom): ";
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
 int main(){
    push(1);
    std::cout << "After the first PUSH top of the satck is: ";
    Top();
    display();

    push(5);
    std::cout << "After the second PUSH top of the stack is: ";
    Top();
    display();

    pop();
    std::cout << "After the first POP operation, top of the stack is: ";
    Top();
    display();

    pop();
    std::cout << "After the second POP operation, top of the stack is: ";
    Top();
    display();
    pop();
    return 0;
 }