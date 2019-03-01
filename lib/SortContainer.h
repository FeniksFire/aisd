#pragma once

#include "Container.h"

template<typename T = int32_t>
class SortContainer : public Container<T> {
public:
	SortContainer(T * array, const size_t size) : Container<T>(array, size){}
	SortContainer() = default;
	virtual ~SortContainer() = default;
	
	void bubbleSort() {
		for (auto i = 0; i < this->getSize() - 1; i++)
			for (auto j = 0; j < this->getSize() - i - 1; j++)
				if (this->valueAt(j) > this->valueAt(j + 1))
					this->swap(this->at(j), this->at(j + 1));
		
	}
	
	void innerSort() {
		for (auto i = 1; i < this->getSize(); i++)
			for (auto j = i - 1; j >= 0; j--)
				if (this->valueAt(j) > this->valueAt(j + 1))
					this->swap(this->at(j), this->at(j + 1));
	}
	
	void selectionSort() {
		for (auto i = this->getSize() - 1; i > 0; i--) {
			int index{0};
			for (auto j = 0; j <= i; j++)
				if (this->valueAt(j) > this->valueAt(index))
					index = j;
			this->swap(this->at(index), this->at(i));
		}
	}
};