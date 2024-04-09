#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex()
    : realPart(0.0), imaginaryPart(0.0)
{
}

Complex::Complex(double r, double i)
    : realPart(r), imaginaryPart(i)
{
}

Complex::Complex(const Complex &c)
    : realPart(c.realPart), imaginaryPart(c.imaginaryPart)
{
}

Complex::~Complex()
{
    // 析构函数
}

double Complex::getReal() const
{
    return realPart;
}

double Complex::getImag() const
{
    return imaginaryPart;
}

void Complex::setReal(double r)
{
    realPart = r;
}

void Complex::setImag(double i)
{
    imaginaryPart = i;
}

Complex Complex::operator+(const Complex &c) const
{
    Complex temp(realPart + c.realPart, imaginaryPart + c.imaginaryPart);
    return temp;
}

Complex Complex::operator-(const Complex &c) const
{
    Complex temp(realPart - c.realPart, imaginaryPart - c.imaginaryPart);
    return temp;
}

Complex Complex::operator*(const Complex &c) const
{
    return Complex(realPart * c.realPart - imaginaryPart * c.imaginaryPart, realPart * c.imaginaryPart + imaginaryPart * c.realPart);
}

bool Complex::operator==(const Complex &c) const
{
    return (realPart == c.realPart && imaginaryPart == c.imaginaryPart);
}

bool Complex::operator!=(const Complex &c) const
{
    return !(*this == c);
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << "(" << c.realPart << ", " << c.imaginaryPart << ")";
    return out;
}

istream &operator>>(istream &in, Complex &c)
{
    in.ignore();
    in >> c.realPart;
    in.ignore();
    in >> c.imaginaryPart;
    in.ignore();
    return in;
}