#include "Number.h"

int main() {

	Number n("122", 10);
	std::cout << n.GetBase() << " " << n.GetDigitsCount() << "\n";
	n.Print();
	n.SwitchBase(16);
	n.Print();

	Number x(n);
	x.Print();

	Number f("001110", 2);
	x = std::move(f);

	x.Print();

	f = x + n;
	f.Print();

	return 0;
}