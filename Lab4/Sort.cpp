#include "Sort.h"
#include <iostream>

Sort::Sort(int count, int min, int max) {
	this->lenght = count;
	this->array = new int[count];
	for (int i = 0; i < count; ++i)
		array[i] = (min + (count / 2 * i) % max);
}

Sort::Sort(const int* v, int count) {
	lenght = count;
	this->array = new int[count];
	for (int i = 0; i < count; ++i)
		array[i] = v[i];
}

Sort::Sort(int count, ...) {
	lenght = count;
	array = new int[lenght];
	int* p = &count;
	p += 2;
	for (int i = 0; i < count; ++i)
		array[i] = *p, p += 2;
}

Sort::Sort(const char* vector) {
	const int lenght = strlen(vector);
	this->array = new int[100];
	int number = 0;
	int temp = 0;
	for (int i = 0; i < lenght; ++i)
		if (vector[i] != ',')
			number = number * 10 + (vector[i]) - '0';
		else {
			this->array[temp] = number;
			number = 0;
			temp++;
		}
	this->array[temp++] = number;
	this->lenght = temp;
}

void Sort::InsertSort(bool ascendent) {
	int i, key, j;
	for (i = 1; i < lenght; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	int aux = arr[i + 1];
	arr[high] = arr[i];
	arr[high] = aux;

	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void Sort::QuickSort(bool ascendent) {
	quickSort(array, 0, lenght);
}

void Sort::BubbleSort(bool ascendent) {
	int i, j;
	bool swapped;
	for (i = 0; i < lenght - 1; i++) {
		swapped = false;
		for (j = 0; j < lenght - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

Sort::~Sort() {
	delete[] this->array;
}

void Sort::Print() {
	for (int i = 0; i < lenght; ++i)
		std::cout << array[i] << " ";
	std::cout << "\n";
}

int Sort::GetElementFromIndex(int index) {
	return this->array[index];
}

int Sort::GetElementsCount() {
	return this->lenght;
}