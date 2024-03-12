#include "Math.h"

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return a + b;
}

int Math::Add(double a, double b, double c) {
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return a * b;
}

int Math::Mul(double a, double b, double c) {
	return a * b * c;
}

/*
int Math::Add(int count, ...) {
	int result = 0;
	va_list list;
	__crt_va_start(list, count);

	for (int i = 0; i < count; ++i)
		result += __crt_va_arg(list, int);

	__crt_va_end(list);

	return result;
}
*/	//VARIANTA CU MODULES

int Math::Add(int count, ...) {
	int* p = &count;
	p += 2;
	int result = 0;
	for (int i = 0; i < count; ++i)
		result += *p, p+=2;
	return result;
}

	//SI VARIANTA CU POINTERI


char* Math::Add(const char* s, const char* t) {
	if (s == nullptr || t == nullptr)
		return nullptr;

	const int lenght = strlen(s) + strlen(t);
	char* buffer = new char[lenght];
	char* start = buffer;

	for (int i = 0; i < strlen(s); ++i)
		*start = *(s + i), start++;
	for (int i = 0; i < strlen(t); ++i)
		*start = *(t + i), start++;

	*start = '\0';

	return buffer;
}

