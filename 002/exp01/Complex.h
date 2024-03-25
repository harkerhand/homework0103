#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{

private:
    double realPart;
    double imaginaryPart;

public:
    Complex();
    Complex(double, double);
    Complex(const Complex &);
    ~Complex();
    double getReal() const;
    double getImag() const;
    void setReal(double);
    void setImag(double);
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;
    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;
    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);
};

#endif