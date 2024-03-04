#include "GlobalFunc.h"
#include <iostream>
Student eu, el;

int main() {
	eu.setName("Iancu Stefan-Teodor");
	eu.setEnglGrade(10.f);
	eu.setHistGrade(10.f);
	eu.setMathGrade(9.80f);
	
	el.setName("Leon Daniel-OOP");
	el.setEnglGrade(8.f);
	el.setHistGrade(10.f);
	el.setMathGrade(9.90f);

	std::cout << compareMath(&eu, &el) << "\n";
	std::cout << compareNames(&eu, &el) << "\n";
	std::cout << compareAverage(&eu, &el) << "\n";
}