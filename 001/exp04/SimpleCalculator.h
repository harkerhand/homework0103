#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H

#include <stdexcept>

class SimpleCalculator
{
public:
    // 简单实现，没必要类外或者分离
    double add(double a, double b)
    {
        return a + b;
    }

    double subtract(double a, double b)
    {
        return a - b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }

    double divide(double a, double b)
    {
        if (b == 0)
        {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        return a / b;
    }
};

#endif // SIMPLECALCULATOR_H