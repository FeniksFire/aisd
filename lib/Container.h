#pragma once

#include <iostream>

template<typename T>
class Container {
public:
	Container(T * array, const size_t size) : array(array), size(size), dynamic(false){}
	Container() = default;
	
	virtual ~Container()
	{
		if (array != nullptr && dynamic)
			delete[] array;
	}
	
	void reserve(const size_t &size)
	{
		this->size = size;
		
		if (array != nullptr)
			delete[] array;
		array = new T[size];
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
	
	T * at(size_t index) const {
		return array + index;
	}
	
	T valueAt(size_t index) const {
		return *(array + index);
	}
	
	friend std::ostream &operator<<(std::ostream &os, const Container &container) {
		for (auto i = container.begin(); i != container.end(); i++)
			os << *i << " ";
		return os;
	}
	
	friend std::istream &operator>>(std::istream &is, const Container &container) {
		for (auto i = container.begin(); i != container.end(); i++)
			is >> *i;
		return is;
	}

protected:
	void swap(T *first, T *second) {
		T temp = *first;
		*first = *second;
		*second = temp;
	}
	
private:
	bool dynamic = true;
	T *array = nullptr;
	size_t size{0};
};