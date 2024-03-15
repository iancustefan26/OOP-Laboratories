#include "Canvas.h"


void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int error = dx - dy;

    while (true) {
        this->matrix[x1][y1] = '*';
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int error2 = 2 * error;
        if (error2 > -dy) {
            error -= dy;
            x1 += sx;
        }
        if (error2 < dx) {
            error += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void Canvas::Clear() {
    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j)
            matrix[j][i] = ' ';
}

void Canvas::SetPoint(int x, int y, char ch) {
    matrix[x][y] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    Canvas::DrawLine(left, bottom, right, bottom, ch);
    Canvas::DrawLine(left, bottom, (left + right) / 2, top, ch);
    Canvas::DrawLine((left + right) / 2, top, right, bottom, ch);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int centerX = x;
    int centerY = y;

    int x1 = 0;
    int y1 = ray;
    int d = 3 - 2 * ray;

    while (x1 <= y1) {
        SetPoint(centerX + x1, centerY + y1, ch);
        SetPoint(centerX - x1, centerY + y1, ch);
        SetPoint(centerX + x1, centerY - y1, ch);
        SetPoint(centerX - x1, centerY - y1, ch);
        SetPoint(centerX + y1, centerY + x1, ch);
        SetPoint(centerX - y1, centerY + x1, ch);
        SetPoint(centerX + y1, centerY - x1, ch);
        SetPoint(centerX - y1, centerY - x1, ch);

        x1++;

        if (d > 0) {
            y1--;
            d = d + 4 * (x1 - y1) + 10;
        }
        else {
            d = d + 4 * x1 + 6;
        }

        if (x1 > y1)
            break;
    } 
}

void Canvas::Deallocate()
{
    for (int i = 0;i < height;i++)
        delete[] matrix[i];
    delete[] matrix;
}
