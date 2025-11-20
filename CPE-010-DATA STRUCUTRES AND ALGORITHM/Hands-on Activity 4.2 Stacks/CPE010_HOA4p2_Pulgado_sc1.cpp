#include<iostream>
#include "STACK.H"

int main(){
	stack <int> s1;
	s1.peek();
	s1.push(10);
	s1.push(5);
	s1.push(1);
	s1.peek();
	s1.pop();
	s1.peek();
	s1.display();
	
	return 0;
}
