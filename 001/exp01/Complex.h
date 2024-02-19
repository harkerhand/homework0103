/*
 * @Date: 2024-02-19 14:33:06
 * @LastEditors: harkerhand harkerhand@outlook.com
 * @LastEditTime: 2024-02-19 14:52:05
 * @FilePath: \homework2\001\exp01\Complex.h
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>
using std::ostream;

class Complex
{

private:
    double realPart;
    double imaginaryPart;

public:
    Complex();
    Complex(double r, double i);
    Complex(const Complex &c);
    ~Complex();
    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);
    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    friend ostream &operator<<(ostream &os, const Complex &c);
};

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

#endif