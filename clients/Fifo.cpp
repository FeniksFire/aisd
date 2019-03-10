#include "Queue.h"
#include <iostream>

void run() {
	Queue<int> queue;
	if(queue.empty())
		std::cout << "Queue is empty\n";
	
	std::cout << "Add elements to queue\n";
	queue.push(7);
	queue.push(12);
	queue.push(25);
	
	if(!queue.empty())
	{
		std::cout << "Queue front: " << queue.front() << "\n";
		std::cout << "Queue back: " << queue.back() << "\n";
	}
	else
		std::cout << "Queue is empty\n";
	
	queue.pop();
	std::cout << "Queue last element was removed\n";
	
	if(!queue.empty())
	{
		std::cout << "Queue front: " << queue.front() << "\n";
		std::cout << "Queue back: " << queue.back() << "\n";
	}
	else
		std::cout << "Queue is empty\n";
}

int main() {
	run();
	return 0;
}