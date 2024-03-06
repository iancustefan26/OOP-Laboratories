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
		if (this->count > 9) {
			int* aux = &this -> numbers[this -> count];
			aux = new int;
		}
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
	for (int num = 0; num < count; ++num)
		std::cout << this->numbers[num] << " ";
	std::cout << "\n";
	//delete[] this->numbers;
}
