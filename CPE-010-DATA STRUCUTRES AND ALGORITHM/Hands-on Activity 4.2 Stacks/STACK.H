#ifndef STACK_H
#define STACK_H
#define MAX 10
#include <iostream>

template<typename T>
class stack{
	private:
		int top = -1;
		T arr[MAX]; 
		
	public:
	//peak
	void peek(){
		if (isEmpty()){
			std::cout << "The stack is empty\n";
		}
		else {
			std::cout << "The value of the stack is: " << arr [top] << std::endl;
		}
	}
	//push
	void push(T value){
		if (isFull()){
			std::cout << "STACK OVERFLOW!" << std::endl;
		}
		else{
			arr[++top] = value;
			std::cout << "Succesfully pushed " << value << std::endl;
		}
	}
	//isEmpty
		bool isEmpty(){
			return (top < 0);
		}
	//isFull
		bool isFull(){
			return (top >= MAX-1);
	}
	//pop
	void pop(){
		if (isEmpty()){
			std::cout << "The stack is empty\n ";
		}
		else {
			std::cout << "Successfully pop " << arr[top--] << std::endl;
		}
	}
	//display
	void display(){
		if (isEmpty()){
			std::cout << "The stack is empty\n ";
		}
		else {
			for (int i = top; i >= 0; i--){
				std::cout << arr[i] << std::endl;
				
			}
		}
	}
};

#endif
