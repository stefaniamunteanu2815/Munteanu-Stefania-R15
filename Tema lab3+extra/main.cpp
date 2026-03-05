#include "Canvas.h"
int main() 
{
    Canvas c(50, 20);

    c.Clear();
    c.DrawRect(2, 1, 20, 8, '#');
    c.FillRect(3, 2, 19, 7, '.');

    c.FillCircle(10, 15, 4, '+');
    c.DrawCircle(10, 15, 4, 'o');

    c.DrawLine(40, 3, 40, 15, '*');

    c.Print();

    return 0;
}