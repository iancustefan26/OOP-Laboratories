#include <iostream>
#include "NumberList.h"

NumberList myVector;

int main() {
	myVector.Init();
	for (int i = 0; i < 30; ++i)
		i % 2 == 0 ? myVector.Add(i % 5) : myVector.Add(i % 2);
	myVector.Print();
	myVector.Sort();
	myVector.Print();
	
	return 0;
}