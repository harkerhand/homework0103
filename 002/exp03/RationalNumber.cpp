#include "RationalNumber.h"
#include <iostream>
using namespace std;

int gcd(int, int);

RationalNumber::RationalNumber(int n, int d)
{
    if (d == 0)
        throw "Invalid denominator";
    numerator = n;
    denominator = d;
    reduction();
}

RationalNumber RationalNumber::operator=(const RationalNumber &rhs)
{
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;
    reduction();
    return *this;
}

RationalNumber RationalNumber::operator+(const RationalNumber &rhs)
{
    RationalNumber temp;
    temp.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
    temp.denominator = denominator * rhs.denominator;
    reduction();
    return temp;
}
RationalNumber RationalNumber::operator-(const RationalNumber &rhs)
{
    RationalNumber temp;
    temp.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
    temp.denominator = denominator * rhs.denominator;
    reduction();
    return temp;
}
RationalNumber RationalNumber::operator*(const RationalNumber &rhs)
{
    RationalNumber temp;
    temp.numerator = numerator * rhs.numerator;
    temp.denominator = denominator * rhs.denominator;
    reduction();
    return temp;
}
RationalNumber RationalNumber::operator/(RationalNumber &rhs)
{
    RationalNumber temp;
    temp.numerator = numerator * rhs.denominator;
    temp.denominator = denominator * rhs.numerator;
    reduction();
    return temp;
}
bool RationalNumber::operator>(const RationalNumber &rhs) const
{
    return (numerator * rhs.denominator) > (rhs.numerator * denominator);
}
bool RationalNumber::operator<(const RationalNumber &rhs) const
{
    return (numerator * rhs.denominator) < (rhs.numerator * denominator);
}
bool RationalNumber::operator>=(const RationalNumber &rhs) const
{
    return !(*this < rhs);
}
bool RationalNumber::operator<=(const RationalNumber &rhs) const
{
    return !(*this > rhs);
}
bool RationalNumber::operator==(const RationalNumber &rhs) const
{
    return (numerator * rhs.denominator) == (rhs.numerator * denominator);
}
bool RationalNumber::operator!=(const RationalNumber &rhs) const
{
    return !(*this == rhs);
}
void RationalNumber::printRational() const
{
    if (denominator == 1)
        cout << numerator;
    else
        cout << numerator << "/" << denominator;
}
void RationalNumber::reduction()
{
    int temp;
    bool isNegative = numerator * denominator < 0;
    if (isNegative)
    {
        numerator = abs(numerator);
        denominator = abs(denominator);
    }
    temp = gcd(numerator, denominator);
    numerator = numerator / temp;
    denominator = denominator / temp;
    if (isNegative)
        numerator = -numerator;
}

int gcd(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}