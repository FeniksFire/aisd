#pragma once

#include <iostream>

template<typename T>
class DoubleLinkedList
{
private:
	class Node{
	public:
		Node(Node * child = nullptr, Node * parent = nullptr) : prev(child), next(parent){}
		
		T getValue() const {
			return value;
		}
		
		void setValue(T value) {
			Node::value = value;
		}
		
		Node *getNext() const {
			return next;
		}
		
		void setNext(Node *next) {
			Node::next = next;
		}
		
		Node *getPrev() const {
			return prev;
		}
		
		void setPrev(Node *prev) {
			Node::prev = prev;
		}
	
	private:
		Node * prev = nullptr;
		Node * next = nullptr;
		T value;
	};
public:
	virtual ~DoubleLinkedList(){}
	
	void insert(unsigned position, const T & entry)
	{
		if(position >= entries) {
			position = entries;
			
			auto newData = new Node(get(position - 1), nullptr);
			newData->setValue(entry);
			if (data == nullptr)
				data = newData;
			else
				back()->setNext(newData);
			entries++;
		}
		
		else
		{
			auto newData = new Node(get(position), get(position+1));
			newData->setValue(entry);
			if(get(position+1))
				get(position+1)->setPrev(newData);
			get(position)->setNext(newData);
			entries++;
			
		}
	}
	
	void replace(unsigned position, const T & entry)
	{
		if(position > entries)
			position = entries;
		auto newData = get(position);
		newData->setValue(entry);
	}
	
	friend std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list) {
		for(int i = 0 ; i < list.size(); i++)
			os<<list.get(i)->getValue()<<" ";
		return os;
	}
	
	void remove(unsigned position)
	{
		if(position <= entries)
		{
			auto newData = get(position);
			auto prev = newData->getPrev();
			auto next = newData->getNext();
			if(prev)
				prev->setNext(next);
			if(next)
				next->setPrev(prev ? prev : nullptr);
			entries--;
			
			if(prev == nullptr)
				data = next;
			
			delete newData;
		}
	}
	
	void removeFind(T value)
	{
		remove(find(value));
	}
	
	int find(const T & value) const
	{
		auto it = data;
		for(int i = 0 ; i < size(); i++) {
			if(it->getValue() == value)
				return i;
			it = it->getNext();
		}
		return -1;
	}
	
	Node * get(int index) const{
		auto it = data;
		for(int i = 0 ; i < index; i++)
			it = it->getNext();
		return it;
	}
	
	Node * front() const
	{
		return get(0);
	}
	
	Node * back() const
	{
		return get(entries-1);
	}
	
	bool empty() const
	{
		return data == nullptr && !size();
	}
	
	size_t size() const {
		return entries;
	}

private:
	Node * data = nullptr;
	
	size_t entries{0};
};