#include<iostream>
#include<stack>

int main(){
    std::stack<int> newStack;

    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    std::cout << "Stack Empty? " << newStack.empty() << std::endl;
    std::cout << "Stack size: " << newStack.size() <<   std::endl;
    std::cout << "Top element of the stack: " << newStack.top() << std::endl;
    newStack.pop();
    std::cout << "Top element of the stack: " << newStack.top() << std::endl;
    std::cout << "Stack size: " << newStack.size() << std::endl;
    return 0;
    
}