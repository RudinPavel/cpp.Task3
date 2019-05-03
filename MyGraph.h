#pragma once
#include <vector>
#include "MyNode.h"
#include "MyEdge.h"
#include <iostream>
using namespace std;

template <class T> class MyGraph
{
private:
	vector<MyNode<T>*> nodes;
	int size = 0;
	int id = 0;

public:
	
	MyGraph() {};

	~MyGraph()
	{
		
		for (int i = 0; i < (int)nodes.size(); i++) // приведение с помощью (int)
		{
			delete nodes[i]; // здесь не имеет смысла использовать virtual деструктор
		}
		cout << "Graph successfully deleted." << endl;
		cout << endl;
		
	}

	void add(T value)
	{
		nodes.push_back(new MyNode<T>(value, ++id));
		size++;
	}

	void remove_last()
	{
		if (size == 0) return;
		nodes.pop_back();
		size--;
	}

	void connect(int from, int to, int weight)
	{
		auto* myEdge = new MyEdge<T>(from, to, weight);
		nodes.at(from)->connect(myEdge);  // nodes[from] не обрабатывается корректно
	}

	void visit_all() 
	{
		if (size == 0)
		{
			cout << "No nodes in the graph." << endl;
			return;
		}
		for (int i = 0; i < (int)nodes.size(); i++)
		{
			nodes[i]->setVisited(true);
		}
	}

	void unvisit_all()
	{
		if (size == 0)
		{
			cout << "No nodes in the graph." << endl;
			return;
		}
		for (int i = 0; i < (int)nodes.size(); i++)
		{
			nodes[i]->setVisited(false);
		}
	}

	void print()
	{
		if (size == 0)
		{
			cout << "No nodes in the graph." << endl;
			return;
		}
		for (int i = 0; i < (int)nodes.size(); i++)
		{
			cout << "Node { id: " << nodes[i]->get_id() << ", value: " << nodes[i]->get_value();
			if (nodes[i]->isVisited()) cout << ", visited }" << endl;
			else cout << ", not visited }" << endl;
		}
		cout << endl;
	}

	void print(bool is_visited)
	{
		if (size == 0)
		{
			cout << "No nodes in the graph" << endl;
			return;
		}
		for (int i = 0; i < (int)nodes.size(); i++)
		{
			if (nodes[i]->isVisited() == is_visited)
			{
				cout << "Node { id: " << nodes[i]->get_id() << ", value: " << nodes[i]->get_value();
				if (nodes[i]->isVisited()) cout << ", visited }" << endl;
				else cout << ", not visited }" << endl;
			}
		}
		cout << endl;
	}

	void print(int index)
	{
		nodes[index]->print();
	}

	int get_size()
	{
		return this->size;
	}
};

