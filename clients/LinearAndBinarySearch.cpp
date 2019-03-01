#include <iostream>
#include "SearchContainer.h"

void init() {
	SearchContainer<int> data;
	size_t size{0};
	int searchNumber{0};
	
	std::cout << "Type array size: ";
	
	std::cin >> size;
	
	data.reserve(size);
	
	std::cin >> data;
	
	std::cout << "Type number that you want find: ";
	
	std::cin >> searchNumber;
	
	const auto linear = data.linearSearch(searchNumber);
	const auto iterativeBinary = data.iterativeBinarySearch(searchNumber);
	const auto recusiveBinary = data.recusiveBinarySearch(searchNumber, 0, data.getSize() - 1);
	
	if (linear == -1)
		std::cout << "Can't find number by linear search\n";
	else
		std::cout << "Linear search index: " << linear << "\n";
	
	if (iterativeBinary == -1 || recusiveBinary == -1)
		std::cout << "Can't find number by binary search\n";
	else {
		std::cout << "Iterative binary search index: " << iterativeBinary << "\n";
		std::cout << "Recusive binary search index: " << recusiveBinary << "\n";
	}
}

int main() {
	init();
	return 0;
}