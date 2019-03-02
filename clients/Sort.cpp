#include "SortContainer.h"

void run() {
	SortContainer<int> data;
	size_t size{0};
	int searchNumber{0};
	
	std::cout << "Type array size: ";
	
	std::cin >> size;
	
	data.reserve(size);
	std::cin >> data;
	
	data.bubbleSort();
	std::cout << "BubbleSort: ";
	std::cout<<data;
	
	data.innerSort();
	std::cout << "\nInnerSort: ";
	std::cout<<data;
	
	data.selectionSort();
	std::cout << "\nSelectionSort: ";
	std::cout<<data;
}

int main() {
	run();
	return 0;
}