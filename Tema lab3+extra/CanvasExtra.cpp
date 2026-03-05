#include "Canvas.h"
#include <stdarg.h>
#include <iostream>
Canvas::Canvas(int lines, int columns)
{
    this->height = lines;
    this->width = columns;
    matrix = new char* [height];//linii
    for (int i = 0; i < height; i++)
    {
        matrix[i] = new char[width];//coloane
    }
    clear();
}
Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
        delete[] matrix[i];
    delete[] matrix;
}
void Canvas::clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
}
void Canvas::print() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << matrix[i][j];
        std::cout << '\n';
    }
}
void Canvas::set_pixel(int x, int y, char value) 
{
    if (y >= 0 && y < height && x >= 0 && x < width) matrix[y][x] = value;
}

void Canvas::set_pixels(int count, ...) //caractere ... sunt int automat
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) 
    {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int value_int = va_arg(args, int);
        set_pixel(x, y, (char)value_int);
    }
    va_end(args);
}