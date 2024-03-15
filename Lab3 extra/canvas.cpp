#include "canvas.h"

Canvas::Canvas(int lines, int columns) {
	this->lines = lines;
	this->columns = columns;
	matrix = new char* [lines];
	for (int i = 0; i < lines; ++i)
		matrix[i] = new char[columns];
	clear();
}

void Canvas::set_pixel(int x, int y, char value) {
	/*char** aux = matrix;
	*aux += columns * x + y;
	**aux = value;
	*/
	matrix[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
	int* p = &count;
	p+=2;
	for (int i = 0; i < count; ++i) {
		int* column = p + 2;
		int* value = column + 2;
		matrix[*p][*column] = char(*value);
		p = value + 2;
	}
}

void Canvas::clear() {
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < columns; ++j)
			matrix[i][j] = ' ';
}

void Canvas::print() const {
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << '\n';
	}
}

void Canvas::Deallocate()
{
	for (int i = 0; i < lines; i++)
		delete[] matrix[i];
	delete[] matrix;
}