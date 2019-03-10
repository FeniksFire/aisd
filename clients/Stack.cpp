#include "Stack.h"
#include <iostream>

void run() {
	Stack<int> stack;
	stack.push(7);
	stack.push(12);
	stack.push(25);
	
	if(!stack.empty())
		std::cout << "Stack top: " << stack.top() << "\n";
	else
		std::cout << "Stack is empty\n";
	
	stack.pop();
	std::cout << "Stack last element was removed\n";
	
	if(!stack.empty())
		std::cout << "Stack top: " << stack.top() << "\n";
	else
		std::cout << "Stack is empty\n";
}

int main() {
	run();
	return 0;
}