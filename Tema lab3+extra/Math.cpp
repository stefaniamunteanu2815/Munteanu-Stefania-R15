
#include "Math.h"
#include <stdarg.h>
#include <cstring>
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return(int)(a + b);
}
int Math::Add(double a, double b, double c)
{
	return(int)(a + b + c);
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return (int)(a * b);
}
int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
}
int Math::Add(int count, ...)//luam din array declarat de compilator
{
	va_list args;//args retine lista de argumente
	va_start(args, count);//initializeaza lista de argumente
	int s = 0;
	for (int i = 0; i < count; i++)
		s += va_arg(args, int);//citeste urmatorul argument din lista
	va_end(args);//curata resursele folosite de va_list 
	return s;
}
char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr) return nullptr;
	int la = static_cast<int>(strlen(a));
	int lb = static_cast<int>(strlen(b));
	char* rez = new char[la + lb + 1];//pt dimensiunea vectorului
	strcpy_s(rez, la + lb + 1, a);
	strcat_s(rez, la + lb + 1, b);
	return rez;
}