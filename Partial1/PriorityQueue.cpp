#include "PriorityQueue.h"

PriorityQueue& PriorityQueue::operator+=(int value){
	if (size == max_size) {
		//print();
		elements[size - 1] = value;
		sortQueue();
		return *this;
	}
	elements[size] = value;
	size++;
	sortQueue();
	return (*this);
}

int PriorityQueue::operator--(int) {

	int aux = elements[size - 1];
	size--;
	return aux;
}

PriorityQueue::operator int() {
	return size;
}

int PriorityQueue::operator()(const char* buffer) {
	if (buffer[0] == 's') {
		return sumQueue();
	}
	if (buffer[1] == 'i') {
		int min = 1e9;
		for (int i = 0; i < size; ++i)
			if (elements[i] < min)
				min = elements[i];
		return min;
	}
	else {
		int max = elements[0];
		for (int i = 0; i < size; ++i)
			if (elements[i] > max)
				max = elements[i];
		return max;
	}

}


