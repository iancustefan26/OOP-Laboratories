#include "Number.h"
#pragma warning(disable: 4996)

Number::Number(const char* value, int base) {
	this->value = new char[strlen(value) + 1];
	this->base = base;
	strcpy(this->value, value);
}

Number::Number(const Number& n) {
	this->base = n.base;
	this->value = new char[strlen(n.value) + 1];
	strcpy(this->value, n.value);
}

Number Number::operator=(Number&& other) noexcept{
	if (this != &other) {
		delete[] value;
		value = new char[strlen(other.value) + 1];
		strcpy(value, other.value);
		base = other.base;

		other.value = nullptr;
		other.base = 0;
	}
	return *this;
}

char* int_to_char(int number) {
	int size = 1;
	int temp = abs(number);
	while (temp /= 10) size++;

	char* char_array = new char[size + 1];

	char* ptr = char_array;
	if (number < 0) {
		*ptr++ = '-';
		number = -number;
	}
	ptr += size;
	*ptr-- = '\0';

	do {
		*ptr-- = '0' + (number % 10);
		number /= 10;
	} while (number != 0);

	return char_array;
}

int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}

Number operator+(Number x, Number y){
	unsigned int base_x = x.GetBase();
	unsigned int base_y = y.GetBase();
	x.SwitchBase(10);
	y.SwitchBase(10);
	int sum = std::atoi(x.value) + std::atoi(y.value);
	Number my(int_to_char(sum), 10);
	my.SwitchBase(max(base_x, base_y));
	x.SwitchBase(base_x);
	y.SwitchBase(base_y);

	return my;
}

Number operator-(Number x, Number y) {
	unsigned int base_x = x.GetBase();
	unsigned int base_y = y.GetBase();
	x.SwitchBase(10);
	y.SwitchBase(10);
	int sum = std::atoi(x.value) - std::atoi(y.value);
	Number my(int_to_char(sum), 10);
	my.SwitchBase(max(base_x, base_y));
	x.SwitchBase(base_x);
	y.SwitchBase(base_y);

	return my;
}

Number::~Number() {
	delete[] this->value;
}

void Number::Print() {
	std::cout << "Value: " << value << "\n";
}

int Number::GetDigitsCount() {
	return strlen(this->value);
}

int Number::GetBase() {
	return this->base;
}


void Number::SwitchBase(int newBase) {
	int lenght = GetDigitsCount();
	int newNumber = 0;
	int i = 0;
	for (i = 0; i < lenght; ++i) {
		int dif;
		if (value[i] >= 65)
			dif = 55;
		else dif = 48;
		newNumber += int(value[i] - dif) * pow(base, lenght - i - 1);
	}
	i = 0;
	char* array = new char[100];
	while (newNumber) {
		array[i] = char(newNumber % newBase) + ((newNumber % newBase > 9) ? 55 : 48);
		newNumber /= newBase;
		i++;
	}
	array[i] = '\0';
	this -> ~Number();
	value = new char[i + 1];
	for (int j = 0; j < i; ++j)
		value[j] = array[i - j - 1];
	value[i] = '\0';
	this->base = newBase;
}
