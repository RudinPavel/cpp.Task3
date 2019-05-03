#pragma once

template <class T> class MyEdge
{
	T from;
	T to;
	int weight = 0;
public:
	MyEdge(T from, T to, int weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}

	T get_to() 
	{
		return to;
	}

	int get_weight()
	{
		return weight;
	}
	~MyEdge() {};
};

