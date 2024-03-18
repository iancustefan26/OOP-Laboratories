#include "Sort.h"

int main() {
	const int* vector = new int[4] {6, 8, 2, 3};
	Sort* array1 = new Sort(5, 0, 1999);
	Sort* array2 = new Sort(vector, 4);
	Sort* array3 = new Sort(6, 865, 34, 56, 21, 3, 7);
	Sort* array4 = new Sort("10,40,100,5,70");

	array1->InsertSort();
	array1->Print();

	array2->BubbleSort();
	array2->Print();

	array3->BubbleSort();
	array3->Print();

	array4->Print();

	delete array1;
	delete array2;
	delete array3;
	delete array4;
}