#pragma once

#include "Container.h"

template<typename T = int32_t>
class SearchContainer : public Container<T> {
public:
	SearchContainer(T * array, const size_t size) : Container<T>(array, size){}
	SearchContainer() = default;
	virtual ~SearchContainer() = default;
	
	int linearSearch(T searchNumber) const {
		for (auto i = this->begin(); i != this->end(); i++)
			if (*i == searchNumber)
				return i - this->begin();
		return -1;
	}
	
	int iterativeBinarySearch(T searchNumber) const {
		auto left = 0;
		auto right = this->getSize() - 1;
		
		while (left <= right) {
			auto middle = (left + right) / 2;
			if (this->valueAt(middle) < searchNumber)
				left = middle + 1;
			else if (this->valueAt(middle) > searchNumber)
				right = middle;
			else
				return middle;
		}
		return -1;
	}
	
	int recursiveBinarySearch(T searchNumber, size_t left, size_t right) const {
		if (left <= right) {
			auto middle = (left + right) / 2;
			if (this->valueAt(middle) < searchNumber)
				return recursiveBinarySearch(searchNumber, middle + 1, right);
			else if (this->valueAt(middle) > searchNumber)
				return recursiveBinarySearch(searchNumber, left, middle);
			else
				return middle;
		}
		return -1;
	}
};