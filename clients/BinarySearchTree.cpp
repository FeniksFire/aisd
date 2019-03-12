#include "BinarySearchTree.h"
#include <iostream>

void run() {
	int root{0};
	std::cout << "Type tree root: ";
	std::cin >> root;
	
	size_t size{0};
	std::cout << "Type tree size: ";
	std::cin >> size;
	

	
	BinarySearchTree<int> tree(root);
	for(int i = 0; i<size; i++)
	{
		int key{0};
		std::cout << "Type tree key: ";
		std::cin>>key;
		tree.insert(key);
	}

	
	int searchNumber{0};
	
	std::cout << "Type searched key: ";
	
	std::cin >> searchNumber;
}

int main() {
	run();
	return 0;
}