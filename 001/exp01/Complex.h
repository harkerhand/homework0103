/*
 * @Date: 2024-02-19 14:33:06
 * @LastEditors: harkerhand harkerhand@outlook.com
 * @LastEditTime: 2024-02-19 14:15:49
 * @FilePath: \homework2\001\exp01\Complex.h
 */

#ifndef COMPLEX_H
#define COMPLEX_H

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