#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
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

#endif