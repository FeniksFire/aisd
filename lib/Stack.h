#pragma once

#include <cstring>

template<typename T>
class Stack {
public:
	~Stack()
	{
		delete []data;
	}
	void push(const T & entry)
	{
		T * newData = new T[entries+1];
		memcpy(newData, data, sizeof(T) * entries);
		delete []data;
		data = newData;
		data[entries] = entry;
		entries++;
	}
	void pop()
	{
		entries--;
		if(!entries)
		{
			entries = 0;
			delete []data;
			data = nullptr;
		}
		else {
			T *newData = new T[entries];
			memcpy(newData, data, sizeof(T)*entries);
			delete[]data;
			data = newData;
		}
	}
	T & top() const
	{
		return data[entries-1];
	}
	
	bool empty() const
	{
		return data == nullptr;
	}
	
	size_t size() const
	{
		return entries;
	}
	
private:
	T * data = nullptr;
	size_t entries{0};
};
