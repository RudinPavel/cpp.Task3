#pragma once

template <class T> class MyNode;

template <class T> class MyEdge
{
private:
	MyNode<T>* from;
	MyNode<T>* to;
	int weight = -1;
public:
	
	MyEdge(MyNode<T>* from, MyNode<T>* to, int weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}

	MyNode<T>* get_from()
	{
		return this->from;
	}

	MyNode<T>* get_to()
	{
		return this->to;
	}

	int get_weight()
	{
		return this->weight;
	}
	~MyEdge() {};
};

