#pragma once
#include <vector>
#include "MyNode.h"
#include "MyEdge.h"
#include <queue>
#include <iostream>
using namespace std;

template <class T> class MyGraph
{
private:
	vector<MyNode<T>*> nodes;
	MyNode<T>** breadth_nodes = new MyNode<T>* [1000];
	MyNode<T>** depth_nodes = new MyNode<T>* [1000];
	int breadth_size = 0;
	int depth_size = 0;
	int size = 0;
	int id = 0;

public:
	vector<MyNode<T>*> return_nodes()
	{
		return this->nodes;
	}

	MyGraph() {};

	~MyGraph()
	{
		for (int i = 0; i < (int)nodes.size(); i++) // приведение с помощью (int)
		{
			delete nodes[i]; 
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

	void connect(int index_from, int index_to, int weight)
	{
		MyNode<T>* from = find_node_by_id(index_from);
		MyNode<T>* to = find_node_by_id(index_to);
		auto* myEdge = new MyEdge<T>(from, to, weight);
		find_node_by_id(index_from)->connect(myEdge);
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

	MyNode<T>* find_node_by_id(int id)
	{
		for (int i = 0; i < (int)nodes.size(); i++)
		{
			if (nodes.at(i)->get_id() == id)
				return nodes.at(i);
		}
		return NULL; // или nullptr
	}

	void depth_bypass(MyNode<T> * current) // рекурсивный обход графа в глубину
	{
		if (current->isVisited())
		{
			return;
		}
		current->setVisited(true);
		depth_nodes[depth_size++] = current;
		for (int i = 0; i < (int)current->get_edges().size(); i++)
		{
			MyNode<T>* helper = current->get_edges().at(i)->get_to();
			depth_bypass(helper);
		}
	}

	void breadth_bypass(MyNode<T> * current) // обход графа в ширину
	{
		queue<MyNode<T>*> neighbors;
		neighbors.push(current);
		while (!neighbors.empty())
		{
			MyNode<T>* helper = neighbors.front();
			helper->setVisited(true);
			breadth_nodes[breadth_size++] = helper;
			neighbors.pop();
			for (int i = 0; i < (int)helper->get_edges().size(); i++)
			{
				if (!helper->get_edges().at(i)->get_to()->isVisited())
				{
					neighbors.push(helper->get_edges().at(i)->get_to());
				}
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

	void print(MyNode<T> * m)
	{
		m->print();
	}

	int get_size()
	{
		return this->size;
	}

	class MyIterator
	{
	private:
		MyNode<T>** current;
		int length = 0;

	public:
		MyIterator(bool is_begin, MyNode<T>* nodes[], int length) // конструктор итератора
		{
			if (is_begin)
			{
				current = nodes;
			}
			else
			{
				current = nodes + length;
			}
		}

		~MyIterator() {} // деструктор итератора

		MyIterator& operator++() // переопределение ... инкремента
		{
			current++;
			return *this;
		}

		const MyIterator operator++(int) // переопределение ... инкремента
		{
			MyIterator new_iterator = *this;
			++(*this);
			return new_iterator;
		}

		MyNode<T>* operator*()
		{
			return *current;
		}

		bool operator==(const MyIterator& second)
		{
			return this->current == second.current; // два итератора равны, если указывают на один и тот же элемент
		}

		bool operator!=(const MyIterator& second)
		{
			return !((*this) == second);
		}
	};
		MyIterator begin_breadth(int start_index)
		{
			breadth_bypass(find_node_by_id(start_index));
			return MyIterator(true, breadth_nodes, breadth_size);
		}

		MyIterator end_breadth()
		{
			return MyIterator(false, breadth_nodes, breadth_size);
		}

		MyIterator begin_depth(int start_index)
		{
			depth_bypass(find_node_by_id(start_index));
			return MyIterator(true, depth_nodes, depth_size);
		}

		MyIterator end_depth()
		{
			return MyIterator(false, depth_nodes, depth_size);
		}
	};

