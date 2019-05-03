#pragma once
#include <vector>
#include <iostream>
#include "MyEdge.h"
using namespace std;

template <class T> class MyNode
{
private:
	T value;
	vector<MyEdge<T>*> edges;
	int id = 0;
	bool is_visited = false;
public:
	MyNode(T value, int id) 
	{
		this->value = value;
		this->id = id;
	}

	~MyNode() 
	{
		for (int i = 0; i < (int)edges.size(); i++)
			delete edges.at(i);
	}

	void print()
	{
		cout << "Node { id: " << id << ", value: " << value;
		if (is_visited) cout << ", visited }" << endl;
		else cout << ", not visited }" << endl;

		for (int i = 0; i < (int)edges.size(); i++)
		{
			cout << (i+1) << ". Connected with NODE[" << edges.at(i)->get_to() << "], weight = " << edges.at(i)->get_weight() << endl;
		}
		cout << endl;
	}

	T get_value()
	{
		return this->value;
	}

	void set_value(T value) 
	{
		this->value = value;
	}

	void connect(MyEdge<T>* m)
	{
		edges.push_back(m);
	}

	int get_id()
	{
		return this->id;
	}

	bool isVisited() {
		return this->is_visited;
	}

	void setVisited(bool answer)
	{
		this->is_visited = answer;
	}

};

