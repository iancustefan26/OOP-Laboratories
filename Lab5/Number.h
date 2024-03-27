#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <string.h>
#include <string>
#pragma warning(disable: 4996)

class Number
{
	char* value;
	unsigned int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& n);
	Number operator=(Number&& other) noexcept;

	friend Number operator+ (Number& x, Number &y);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

#endif
