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

	f = x + n + n;
	f.Print();

	std::cout << "\n\n";

	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FF", 16);

	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
	{
		printf("n1[%d]=%c\n", tr, n1[tr]);
	}
	n1.Print();
	n2.Print();
	n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
	n1.SwitchBase(2);
	n1.Print();

	return 0;
}