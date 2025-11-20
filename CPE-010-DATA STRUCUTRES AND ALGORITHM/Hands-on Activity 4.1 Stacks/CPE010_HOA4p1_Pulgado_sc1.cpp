#include<iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData;

void push();
void pop();
void Top();
bool isEmpty();
void display();

int main(){
    int choice;
    std::cout<<"Enter number of max elements for new stack: ";
    std::cin >> i;

    while (true){
        std::cout << "\nStack operations: " << std::endl;
        std::cout << "1. PUSH, 2. POP, 3. TOP, 4. ISEMPTY, 5. DISPLAY, 6. EXIT" << std::endl;
        std::cout << "choice: ";
        std::cin >> choice;

        switch (choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: Top(); break;
            case 4: std::cout << (isEmpty() ? "Stack is empty" : "Stack is not empty") << std::endl; break;
            case 5: display(); break;
            case 6: return 0;        
            default: std::cout << "Invalid choice." << std::endl;
        }
    }
    return 0;
}

bool isEmpty(){
    return (top == -1);
}

void push(){
    if(top == i-1){
        std::cout << "Stack Overflow." << std::endl;
        return;
    }
    std::cout << "Enter new value: ";
    std::cin >> newData;
    stack[++top] = newData;
}

void pop(){
    if (isEmpty()){
        std::cout << "Stack Underflow." << std::endl;
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl;
    top--;
}

void Top(){
    if (isEmpty()){
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    std::cout << "The element on the top of the stack is: " << stack[top] << std::endl;
}

void display(){
    if (isEmpty()){
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    for (int j = top; j >= 0; j--){
        std::cout << stack[j] << " ";
    }
    std::cout << std::endl;
}