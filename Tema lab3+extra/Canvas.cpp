#include "Canvas.h"
#include <iostream>
#include <cmath>
using namespace std;
Canvas::Canvas(int w, int h)
{
    this->width = w;
    this->height = h;
    matrix = new char* [height];//linii
    for (int i = 0; i < height; i++) 
    {
        matrix[i] = new char[width];//coloane
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' '; // pixel gol
    }
}
Canvas::~Canvas() 
{
    for (int i = 0; i < height; i++)
        delete[] matrix[i];
    delete[] matrix;
}
void Canvas::Clear() 
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
}
void Canvas::Print() 
{
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
            std::cout << matrix[i][j];
        std::cout << '\n';
    }
}
void Canvas::SetPoint(int x, int y, char ch) 
{
    if (x >= 0 && x < width && y >= 0 && y < height) matrix[y][x] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) 
{
    for (int x = left; x <= right; x++) 
    {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }
    for (int y = top; y <= bottom; y++) 
    {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) 
{
    for (int y = top; y <= bottom; y++)
        for (int x = left; x <= right; x++)
            SetPoint(x, y, ch);
}
void Canvas::DrawCircle(int cx, int cy, int r, char ch) 
{
    for (int y = cy - r; y <= cy + r; y++) 
    {
        for (int x = cx - r; x <= cx + r; x++) 
        {
            int dx = x - cx;
            int dy = y - cy;
            int d2 = dx * dx + dy * dy;
            if (std::abs(d2 - r * r) <= r) SetPoint(x, y, ch);
        }
    }
}
void Canvas::FillCircle(int cx, int cy, int r, char ch) 
{
    for (int y = cy - r; y <= cy + r; y++) 
    {
        for (int x = cx - r; x <= cx + r; x++) 
        {
            int dx = x - cx;
            int dy = y - cy;
            if (dx * dx + dy * dy <= r * r) SetPoint(x, y, ch);
        }
    }
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) //cu Brasenham's algorithm
{
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (true) 
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) 
        {
            err += dx;
            y1 += sy;
        }
    }
}
