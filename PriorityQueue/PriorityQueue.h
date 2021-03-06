#pragma once
#include <stdexcept>
#include <iostream>

template <class T>
class PQData 
{
public:
	PQData(){}
	PQData(unsigned int p, int v) {
		priority = p;
		value = v;
	}

	unsigned int priority;
	T value;
};

class EmptyException {

};


class PriorityQueue
{
public:
	PriorityQueue(int n);
	~PriorityQueue();

	void insert(unsigned int p, int x);
	void insert(PQData<int> data);
	/**
		 for every key of value x sets new priority p if p is higher than current priority of the key
	*/
	void priority(unsigned int p, int x);

	int top();
	int pop();
	bool isEmpty();

	void print();

private:
	void swap(int i1, int i2);
	void bubbleUp(int i, PQData<int> data);
	void bubbleDown(int i);

	PQData<int>* tab;
	int size;
	const int max;
};

