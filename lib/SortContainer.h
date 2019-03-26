#pragma once

#include "Container.h"
#include <functional>

template<typename T = int32_t>
class SortContainer : public Container<T> {
public:
	SortContainer(T *array, const size_t size) : Container<T>(array, size) {}
	
	SortContainer() = default;
	
	virtual ~SortContainer() = default;
	
	void bubbleSort()
	{
		for (auto i = 0; i < this->getSize() - 1; i++)
			for (auto j = 0; j < this->getSize() - i - 1; j++)
				if (this->valueAt(j) > this->valueAt(j + 1))
					this->swap(this->at(j), this->at(j + 1));
	}
	
	void innerSort()
	{
		for (auto i = 1; i < this->getSize(); i++)
			for (auto j = i - 1; j >= 0; j--)
				if (this->valueAt(j) > this->valueAt(j + 1))
					this->swap(this->at(j), this->at(j + 1));
	}
	
	void selectionSort()
	{
		for (auto i = this->getSize() - 1; i > 0; i--) {
			int index{0};
			for (auto j = 0; j <= i; j++)
				if (this->valueAt(j) > this->valueAt(index))
					index = j;
			this->swap(this->at(index), this->at(i));
		}
	}
	
	int partition(size_t first, size_t last, std::function<bool(T)> condition)
	{
		auto i = first;
		
		for(auto j = first; j < last; j++)
		{
			if(condition(this->valueAt(j)))
			{
				this->swap(this->at(i), this->at(j));
				i++;
			}
		}
		this->swap(this->at(i), this->at(last));
		return i;
	}
	
	void threeWayPartition(std::function<bool(T)> condition, std::function<bool(T)> isPivot)
	{
		int right = this->getSize() - 1;
		int left = 0, mid = 0;
		
		while (mid <= right) {
			if (!condition(this->valueAt(mid)) && !isPivot(this->valueAt(mid)))
			{
				this->swap(this->at(left), this->at(mid));
				left++;
				mid++;
			}
			else if (condition(this->valueAt(mid)))
			{
				this->swap(this->at(mid), this->at(right));
				right--;
			}
			else
				mid++;
		}
	}
	
	void quickSort(int first, int last)
	{
		if(first < last)
		{
			auto pivot = this->valueAt(last);
			auto pivotPos = partition(first, last, [&pivot](int val)->bool{return val < pivot;});
			quickSort(first, pivotPos-1);
			quickSort(pivotPos+1, last);
		}
	}
};