#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>

class PriorityQueue {
private:
	int size;
	int* elements;
	int max_size;
	void sortQueue() {
		for(int i = 0; i < size;++i)
			for(int j = i + 1 ;j < size; ++j)
				if (elements[i] < elements[j]) {
					int aux = elements[i];
					elements[i] = elements[j];
					elements[j] = aux;
				}
	}
	int sumQueue() const {
		int s = 0;
		for (int i = 0; i < size; ++i)
			s += elements[i];
		return s;
	}
public:
	PriorityQueue(int max_size) : max_size(max_size){
		size = 0;
		elements = new int[max_size + 1];
	}
	void print() const {
		for (int i = 0; i < size; ++i)
			std::cout << elements[i] << " ";
		std::cout << "\n";
	}
	PriorityQueue& operator+=(int value);
	int operator--(int);
	operator int();
	int operator()(const char* buffer);
	~PriorityQueue() {
		delete[] elements;
	}
};

#endif // !PRIORITYQUEUE_H
