#include "SortContainer.h"

void runFirst() {
	SortContainer<int> data;
	size_t size{0};
	
	std::cout << "Type array size: ";
	
	std::cin >> size;
	
	data.reserve(size);
	
	std::cout << "Type array elements: ";
	
	std::cin >> data;
	
	data.quickSort(0, size-1);
	std::cout << "QuickSort sorting...\n";
	std::cout << "Array: ";
	
	std::cout<<data;
}


void runSecond() {
	SortContainer<int> data;
	size_t size{0};
	unsigned range{0};
	
	std::cout << "Type array size: ";
	
	std::cin >> size;
	
	data.reserve(size);
	
	std::cout << "Type array elements: ";
	
	std::cin >> data;
	
	std::cout << "Type range size: ";
	
	std::cin >> range;
	
	auto pos = data.partition(0, size-1, [](int val){return val%2==0;});
	
	
	if(data.valueAt(pos)%2==0)
		pos++;
	data.quickSort(0, pos-1);
	data.quickSort(pos, size-1);
	
	std::cout << "Array after partition and quicksort: ";
	std::cout<<data;
	
	size_t value{0};
	
	unsigned int max{0};
	for(int i = 0; i<pos; i++)
	{
		size_t tmp{0};
		for(int j = data.valueAt(i); j<=data.valueAt(i)+range; j++)
			tmp += data.count(j);
		if(tmp>max)
		{
			value = data.valueAt(i);
			max = tmp;
		}
	}
	std::cout<<"\nRange: <"<<value<<", "<<value+range<<">";
}

int main() {
	runSecond();
	return 0;
}