#pragma once
class Number 
{
    char* value;
    int digitCount;
    int base;
    static int charToVal(char c);
    static char valToChar(int v);
    long long toBase10() const;
    void fromBase10(long long n, int b);

public:
    Number(const char* value, int base);
    Number(const Number& to_copy_from);
    Number(Number&& to_move_from);
    ~Number();
    Number(int value); // constructor pentru conversie de la int
    Number& operator=(const Number& other);
    Number& operator=(Number&& to_move_from);
    Number& operator=(const char* val);
    Number& operator=(int val);

    Number& operator+=(const Number& n);
    friend Number operator+(const Number& x, const Number& y);
    friend Number operator-(const Number& x, const Number& y);
    bool operator>(Number y);
    bool operator<(Number y);
    bool operator>=(Number y);
    bool operator<=(Number y);
    bool operator==(Number y);
    char operator[](int index);
    Number operator--(int); // postfix
    Number operator--();    // prefix

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};