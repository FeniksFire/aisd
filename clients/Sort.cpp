#include <iostream>

template<typename T>
class Container {
public:
	Container() = default;
	virtual ~Container() = default;
	
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
	
	void bubbleSort() {
		for (auto i = 0; i < size - 1; i++)
			for (auto j = 0; j < size - i - 1; j++)
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
		
	}
	
	void innerSort() {
		for (auto i = 1; i < size; i++)
			for (auto j = i - 1; j >= 0; j--)
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
	}
	
	
	void selectionSort() {
		for (auto i = size - 1; i > 0; i--) {
			int index{0};
			for (auto j = 0; j <= i; j++)
				if (array[j] > array[index])
					index = j;
			swap(&array[index], &array[i]);
		}
	}
	
	void print() const {
		for (auto *i = begin(); i != end(); i++)
			std::cout << *i << " ";
	}

private:
	void swap(T *first, T *second) {
		T temp = *first;
		*first = *second;
		*second = temp;
	}
	
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
	
	data.bubbleSort();
	std::cout << "BubbleSort: ";
	data.print();
	
	data.innerSort();
	std::cout << "\nInnerSort: ";
	data.print();
	
	data.selectionSort();
	std::cout << "\nSelectionSort: ";
	data.print();
}

int main() {
	init();
	return 0;
}