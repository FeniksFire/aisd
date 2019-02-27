#include <iostream>

template<typename T>
class Container {
public:
	Container() = default;
	virtual ~Container() {}
	
	void reserve(const size_t &size) {
		this->size = size;
		
		if (array != nullptr)
			delete[] array;
		array = new T[size];
		
		for (auto *i = begin(); i != end(); i++)
			std::cin >> *i;
	}
	
	T *begin() const noexcept {
		return array;
	}
	
	T *end() const noexcept {
		return array + size;
	}
	
	size_t getSize() const {
		return size;
	}
	
	int linearSearch(T searchNumber) const {
		for (auto i = begin(); i != end(); i++)
			if (*i == searchNumber)
				return i - begin();
		return -1;
	}
	
	int iterativeBinarySearch(T searchNumber) const {
		auto left = 0;
		auto right = size - 1;
		
		while (left < right) {
			auto middle = (left + right) / 2;
			if (array[middle] < searchNumber)
				left = middle + 1;
			else if (array[middle] > searchNumber)
				right = middle;
			else
				return middle;
		}
		return -1;
	}
	
	int recusiveBinarySearch(T searchNumber, size_t left, size_t right) const {
		if (left < right) {
			auto middle = (left + right) / 2;
			if (array[middle] < searchNumber)
				return recusiveBinarySearch(searchNumber, middle + 1, right);
			else if (array[middle] > searchNumber)
				return recusiveBinarySearch(searchNumber, left, middle);
			else
				return middle;
		}
		return -1;
	}

private:
	T *array = nullptr;
	size_t size{0};
};

void init() {
	Container<int> data;
	size_t size{0};
	int searchNumber{0};
	
	std::cout << "Type array size: ";
	
	std::cin >> size;
	
	data.reserve(size);
	
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