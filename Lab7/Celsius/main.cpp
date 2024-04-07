#include <iostream>

float operator"" _Kelvin(unsigned long long x) {
	return x - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long x) {
	return (x - 32.f) * 5.f / 9.f;
}

int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	printf("%f %f", a, b);
	return 0;
}