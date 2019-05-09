#pragma once
#include "MyNode.h"
#include <vector>
using namespace std;

template <class T> class MyIterator
{
private:
	MyNode<T>* current;
	
public:
	MyIterator(MyNode<T>* const head) { this->current = head; }

	T get_value() { return current->get_value(); }

	MyIterator operator++(int) 
	{
		MyIterator old = *this;// указатель на текущий итератор
		//current = current->edges[0];
		return old;
	}
	MyIterator& operator++() 
	{
	
			//current = current->edges[0];
		current++;
		return this;
	}
	bool operator==(const MyIterator& second) { return this->current == second->current; }
	bool operator!=(const MyIterator& second) { return this->current != second->current; }
	MyNode<T>& operator*() { return *current; } // разыменовать 
	~MyIterator() {};
	
	MyIterator beginWidth(T t)
	{

	}
	MyIterator endWidth(T t)
	{

	}
	MyIterator beginDepth(T t)
	{

	}
	MyIterator endDepth(T t)
	{

	}

};
/*

	class Iterator
	{
	private:
		vector<MyNode<T>*> _nodes;
		//increment_operator++
	};
*/
