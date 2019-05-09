#pragma once
#include <vector>
#include "MyNode.h"
#include "MyEdge.h"
#include "MyIterator.h"
#include <queue>
#include <iostream>
using namespace std;

template <class T> class MyGraph
{
private:
	vector<MyNode<T>*> nodes;
	int size = 0;
	int id = 0;

public:
	vector<MyNode<T>*> return_nodes() 
	{
		return this->nodes;
	}

	MyGraph() {};

	MyIterator<T> begin() { return MyIterator<T>(nodes.front()); }

	MyIterator<T> end() { return MyIterator<T>(nodes.back()); }

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
		findNodeById(from)->connect(myEdge);  // nodes[from] не обрабатывается корректно
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

	MyNode<T>* findNodeById(int id)
	{
		for (int i = 0; i < (int)nodes.size(); i++)
		{
			if (nodes.at(i)->get_id() == id)
				return nodes.at(i);
		}
	}

	void depth_bypass(MyNode<T>* current) // рекурсивный обход графа в глубину
	{
		if (current->isVisited())
		{
			return;
		}
		current->setVisited(true);
		for (int i = 0; i < (int)current->get_edges().size(); i++)
		{
			MyNode<T>* helper = findNodeById(current->get_edges().at(i)->get_to());
			depth_bypass(helper);
		}
	}

	void breadth_bypass(MyNode<T>* current) // обход графа в ширину
	{
		queue<MyNode<T>*> neighbors;
		neighbors.push(current);
		while (!neighbors.empty())
		{
			MyNode<T>* helper = neighbors.front();
			helper->setVisited(true);
			neighbors.pop();
			for (int i = 0; i < (int)helper->get_edges().size(); i++)
			{
				if (!(findNodeById(helper->get_edges().at(i)->get_to())->isVisited()))
					neighbors.push(findNodeById(helper->get_edges().at(i)->get_to()));
			}
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

	void print(MyNode<T>* m)
	{
		m->print();
	}

	int get_size()
	{
		return this->size;
	}
};

