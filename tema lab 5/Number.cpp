#include "Number.h"
#include <iostream>
#include <cstring>
using namespace std;
Number::~Number() 
{
    delete[] value;
}
int Number::charToVal(char c) 
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

char Number::valToChar(int v) 
{
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}
Number::Number(int val) 
{
    this->value = nullptr;
    this->base = 10;
    fromBase10(val, 10);
}
Number::Number(const char* val, int base) 
{
    this->base = base;
    this->digitCount = strlen(val);
    this->value = new char[digitCount+1];

    for (int i = 0; i < digitCount; i++)
        this->value[i] = val[i];
    value[digitCount] = '\0';
}
Number::Number(const Number& to_copy_from)
{
    this->digitCount = to_copy_from.digitCount;
    this->base = to_copy_from.base;

    this->value = new char[this->digitCount + 1];
    for (int i = 0; i < this->digitCount; i++)
        this->value[i] = to_copy_from.value[i];
}
Number::Number(Number&& to_move_from)
{
    this->digitCount = to_move_from.digitCount;
    this->base = to_move_from.base;
    this->value = to_move_from.value;

    to_move_from.value = nullptr;
    to_move_from.digitCount = 0;
}
Number& Number::operator=(const Number& other) 
{
    if (this != &other) 
    {
        delete[] value;
        this->digitCount = other.digitCount;
        this->base = other.base;
        this->value = new char[digitCount + 1];
        for (int i = 0; i <= digitCount; i++)
            this->value[i] = other.value[i];
    }
    return *this;
}

Number& Number::operator=(Number&& to_move_from) 
{
    if (this != &to_move_from) 
    {
        delete[] value;
        this->value = to_move_from.value;
        this->digitCount = to_move_from.digitCount;
        this->base = to_move_from.base;
        to_move_from.value = nullptr;
        to_move_from.digitCount = 0;
    }
    return *this;
}

Number& Number::operator=(const char* val) 
{
    delete[] value;
    int len = 0;
    while (val[len] != '\0') len++;
    this->digitCount = len;
    this->value = new char[digitCount + 1];
    for (int i = 0; i <= digitCount; i++)
        this->value[i] = val[i];
    return *this;
}

Number& Number::operator=(int val) 
{
    fromBase10(val, this->base);
    return *this;
}
Number operator+(const Number& x, const Number& y) 
{
    int b;
    if (x.base > y.base) b = x.base;
    else b = y.base;
    long long sum = x.toBase10() + y.toBase10();
    Number rez("0", b);
    rez.fromBase10(sum, b);
    return rez;
}
Number operator-(const Number& x, const Number& y) 
{
    int b;
    if (x.base > y.base) b = x.base;
    else b = y.base;
    long long diff = x.toBase10() - y.toBase10();
    Number rez("0", b);
    rez.fromBase10(diff, b);
    return rez;
}
long long Number::toBase10() const 
{
    long long rez = 0;
    for (int i = 0; i < digitCount; i++)
        rez = rez * base + charToVal(value[i]);
    return rez;
}
void Number::fromBase10(long long n, int b) 
{
    char x[100];
    int poz = 0;
    if (n == 0) x[poz++] = '0';
    else 
    {
        while (n > 0) 
        {
            x[poz++] = valToChar(n % b);
            n /= b;
        }
    }
    if (value) delete[] value;
    digitCount = poz;
    base = b;
    value = new char[digitCount + 1];
    for (int i = 0; i < digitCount; i++)
        value[i] = x[digitCount - i - 1];
    value[digitCount] = '\0';
}
Number& Number::operator+=(const Number& n) 
{
    *this = *this + n;
    return *this;
}
bool Number::operator>(Number y) 
{
    return this->toBase10() > y.toBase10();;
}

bool Number::operator<(Number y) 
{
    return this->toBase10() < y.toBase10();
}

bool Number::operator>=(Number y) 
{
    return this->toBase10() >= y.toBase10();
}

bool Number::operator<=(Number y) 
{
    return this->toBase10() <= y.toBase10();
}

bool Number::operator==(Number y) 
{
    return this->toBase10() == y.toBase10();
}

char Number::operator[](int index) 
{
    if (index < 0 || index >= digitCount) return -1;
    return value[index];
}

Number Number::operator--() 
{ // prefix
    if (digitCount > 0) 
    {
        for (int i = 1; i < digitCount; i++)
            value[i - 1] = value[i];
        digitCount--;
        value[digitCount] = '\0';
    }
    return *this;
}

Number Number::operator--(int) 
{ // postfix
    Number temp(*this);
    if (digitCount > 0) 
    {
        digitCount--;
        value[digitCount] = '\0';
    }
    return temp;
}

void Number::SwitchBase(int newBase) 
{
    long long n = toBase10();
    fromBase10(n, newBase);
}

void Number::Print() 
{
    if (value) cout << value << endl;
}

int Number::GetDigitsCount() { return digitCount; }
int Number::GetBase() { return base; }