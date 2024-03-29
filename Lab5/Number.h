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
	Number(Number&& n) noexcept;
	Number operator=(Number&& other) noexcept;
	Number(const unsigned int n);

	unsigned int GetBase10() const {
		int result = 0, power = 1, i;
		for (i = strlen(value); i >= 0; --i) {
			result = result + (value[i] - '0') * power;
			power = power * base;
		}
		return result;
	}

	friend Number operator+ (Number x, Number y);
	friend Number operator- (Number x, Number y);
	char& operator[] (int index) {
		return this->value[index];
	};
		
	bool operator<(const Number& n);
	bool operator<=(const Number& n);
	void operator=(const char* buffer);
	void operator=(const unsigned int n);
	void operator+=(Number& n);
	bool operator>=(const Number& n);
	bool operator>(const Number& n);
	Number& operator++() {
		Number one = { "1", 10 };
		(*this) += one;
		return *this;
	}
	Number operator++(int) {
		Number copy(*this);
		++(*this);
		return copy;
	}

	Number& operator--() {
		for (int i = 1; i < strlen(this->value); ++i)
			this->value[i - 1] = this->value[i];
		this->value[strlen(this->value) - 1] = '\0';
		return *this;
	}
	Number operator--(int) {
		Number copy(*this);
		this->value[strlen(this->value) - 1] = '\0';
		return copy;
	}


	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

#endif
