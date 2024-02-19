#include "Complex.h"
#include <ostream>
using std::ostream;

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

ostream &operator<<(ostream &out, const Complex &c)
{
    out << "<" << c.realPart << ", " << c.imaginaryPart << ">";
    return out;
}