#include "Math.h"
#include <iomanip>
Math mate;

int main() {
	
	std::cout << mate.Add(2, 3) << "\n";
	std::cout << mate.Add(2, 3, 4) << "\n";
	std::cout << mate.Add(2.0, 3.6) << "\n";
	std::cout << mate.Add(2.3, 3.2, 2.1) << "\n";
	std::cout << mate.Add("Leo e cel", " mai smecher") << "\n";
	std::cout << mate.Mul(2, 3) << "\n";
	std::cout << mate.Mul(2, 3, 7) << "\n";
	std::cout << mate.Mul(2.1, 3.7) << "\n";
	std::cout << mate.Mul(2.9, 3.1, 10.12) << "\n";
	std::cout << mate.Add(7, 1, 2, 3, 4, 5, 6, 7);

	return 0;
}