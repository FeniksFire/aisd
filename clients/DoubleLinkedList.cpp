#include "DoubleLinkedList.h"
#include <iostream>

void run() {
	DoubleLinkedList<int> list;
	
	if(list.empty())
		std::cout << "List is empty\n";
	
	std::cout << "Add elements to list\n";
	list.insert(0, 3);
	list.insert(1, 3);
	list.insert(2, 3);
	list.insert(3, 3);
	
	std::cout << "List elements: \n";
	std::cout<<list<<"\n";
	
	std::cout << "\nInsert 2 in index 2\n";
	
	list.insert(2, 2);
	
	std::cout << "List elements: \n";
	std::cout<<list<<"\n";
	
	std::cout << "\nReplace index 2 with 5\n";
	
	list.replace(2, 5);
	
	std::cout << "List elements: \n";
	std::cout<<list<<"\n";
	
	std::cout << "\nRemove index 1\n";
	
	list.remove(1);
	
	std::cout << "List elements: \n";
	std::cout<<list<<"\n";
	
	std::cout << "\nElement 5 have index: "<<list.find(5)<<"\n";
	
	std::cout << "\nRemove 5 from list\n";
	
	list.removeFind(5);
	
	std::cout << "List elements: \n";
	std::cout<<list<<"\n";
	

	
	
}

int main() {
	run();
	return 0;
}