#include <iostream>
#include <algorithm>
#include "NumberList.h"

void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	try {
		this->numbers[count] = x;
		this->count++;
		return 1;
	}
	catch (const std::exception& e) {
		std::cerr << "Error adding the X: " << e.what() << "\n";
		return 0;
	}
}

void NumberList::Sort() {
	std::sort(this->numbers, this->numbers + count - 1);
}

void NumberList::Print() {
	for (int num : numbers)
		std::cout << num << " ";
	std::cout << "\n";
}
