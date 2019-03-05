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
	
	void twoWayPartition(std::function<bool(T)> condition)
	{
		int right = this->getSize() - 1;
		int left = 0;
		while (left < right) {
			if (!condition(this->valueAt(left)))
				left++;
			if (condition(this->valueAt(right)))
				right--;
			if (left >= right)
				break;
			if (condition(this->valueAt(left)) && !condition(this->valueAt(right)))
				this->swap(this->at(left), this->at(right));
		}
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
	
	void quickSort(int low, int hight)
	{
		if(low < hight)
		{
			auto p = partition(low, hight);
			quickSort(low, p-1);
			quickSort(p+1, hight);
		}
	}

	int partition(int low, int hight)
	{
		auto pivot = this->valueAt(hight);
		auto i = low;
		
		for(auto j = low; j<hight; j++)
		{
			auto first = this->valueAt(j);
			auto second = this->valueAt(i);
			if(this->valueAt(j) < pivot)
			{
				this->swap(this->at(i), this->at(j));
				i++;
			}
		}
		this->swap(this->at(i), this->at(hight));
		return i;
	}
};