#pragma once

template <class T> class MyEdge
{
private:
	int index_from = -1;
	int index_to = -1;
	int weight = -1;
public:
	
	MyEdge(int index_from, int index_to, int weight)
	{
		this->index_from = index_from;
		this->index_to = index_to;
		this->weight = weight;
	}

	int get_from()
	{
		return this->index_from;
	}

	int get_to()
	{
		return this->index_to;
	}

	int get_weight()
	{
		return this->weight;
	}
	~MyEdge() {};
};

