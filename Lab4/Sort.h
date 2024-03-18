
#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <cstdarg>



class Sort
{
    int* array;
    int lenght;
public:
    Sort(int count, int min, int max);
    Sort(int count) : array(new int[count]{4, 3, 1, 199}), lenght(count) {};
    Sort(const int *v, int count);
    Sort(int count, ...);
    Sort(const char* vector);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    ~Sort();
};

#endif