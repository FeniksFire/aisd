#include <iostream>
#include <vector>
#include <algorithm>

void run() {
	std::vector<int> v;
	
	size_t size{0};
	std::cout << "Type heap size: ";
	std::cin >> size;
	
	for(int i = 0; i<size; i++)
	{
		int value{0};
		std::cout << "Type value: ";
		std::cin>>value;
		v.push_back(value);
	}
	
	std::make_heap(v.begin(), v.end());
	
	std::cout << "\nheap:\t";
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
}

int main() {
	run();
	return 0;
}