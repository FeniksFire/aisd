#include "SortContainer.h"

void runFirst() {
	SortContainer<int> data;
	size_t size{0};
	
	std::cout << "Type array size: ";
	
	std::cin >> size;
	
	data.reserve(size);
	std::cin >> data;
	
	data.quickSort(0, size-1);
	std::cout << "QuickSort: ";
	std::cout<<data;
}

int main() {
	runFirst();
	return 0;
}