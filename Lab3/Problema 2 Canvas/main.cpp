#include "Canvas.h"

Canvas box(20, 20);

int main() {
	box.Clear();
	box.DrawLine(1, 1, 19, 19, '*');
	box.DrawCircle(10, 10, 7, '*');
	box.DrawRect(1, 10, 15, 19, '*');
	box.Print();	
	return 0;
}