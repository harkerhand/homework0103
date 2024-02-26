#include <iostream>
#include <stdexcept>
#include <cstring>
#include "HugeInteger.h"

using namespace std;

HugeInteger::HugeInteger(int i)
{
    for (int j = 0; j < 40; j++)
    {
        integer[j] = i % 10;
        i = i / 10;
        if (i == 0)
            break;
    }
}

HugeInteger::HugeInteger(const char *other)
{
    int i = 0, other_Len = strlen(other);
    for (int j = other_Len - 1; j >= 0; j--)
    {
        if (other[j] >= '0' && other[i] <= '9')
        {
            integer[i] = other[j] - '0';
            i++;
        }
        else
            throw invalid_argument("Not a number");
    }
}

HugeInteger HugeInteger::add(const HugeInteger &other) const
{
    HugeInteger result;
    int carry = 0;
    for (int i = 0; i < 40; i++)
    {
        result.integer[i] = integer[i] + other.integer[i] + carry;
        carry = result.integer[i] / 10;
        result.integer[i] = result.integer[i] % 10;
    }
    return result;
}

HugeInteger HugeInteger::add(int other) const
{
    HugeInteger result(other);
    return this->add(result);
}

HugeInteger HugeInteger::add(const char *other) const
{
    HugeInteger result(other);
    return this->add(result);
}

HugeInteger HugeInteger::subtract(const HugeInteger &other) const
{
    HugeInteger result;
    int carry = 0;
    for (int i = 0; i < 40; i++)
    {
        result.integer[i] = integer[i] - other.integer[i] - carry;
        if (result.integer[i] < 0)
        {
            result.integer[i] += 10;
            carry = 1;
        }
        else
            carry = 0;
    }
    return result;
}

HugeInteger HugeInteger::subtract(int other) const
{
    HugeInteger result(other);
    return this->subtract(result);
}

HugeInteger HugeInteger::subtract(const char *other) const
{
    HugeInteger result(other);
    return this->subtract(result);
}

bool HugeInteger::isEqualTo(const HugeInteger &other) const
{
    for (int i = 0; i < 40; i++)
    {
        if (integer[i] != other.integer[i])
            return false;
    }
    return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger &other) const
{
    return !this->isEqualTo(other);
}

bool HugeInteger::isGreaterThan(const HugeInteger &other) const
{
    for (int i = 39; i >= 0; i--)
    {
        if (integer[i] > other.integer[i])
            return true;
        else if (integer[i] < other.integer[i])
            return false;
    }
    return false;
}

bool HugeInteger::isLessThan(const HugeInteger &other) const
{
    for (int i = 39; i >= 0; i--)
    {
        if (integer[i] < other.integer[i])
            return true;
        else if (integer[i] > other.integer[i])
            return false;
    }
    return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger &other) const
{
    return !this->isLessThan(other);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger &other) const
{
    return !this->isGreaterThan(other);
}

bool HugeInteger::isZero() const
{
    for (int i = 0; i < 40; i++)
    {
        if (integer[i] != 0)
            return false;
    }
    return true;
}

void HugeInteger::input(const char *other)
{
    HugeInteger a(other);
    *this = a;
}

void HugeInteger::output() const
{
    bool flag = false;
    for (int i = 39; i >= 0; i--)
    {
        if (integer[i] != 0)
            flag = true;
        if (flag == true)
            cout << integer[i];
    }
    cout << endl;
}

ostream &operator<<(ostream &output, const HugeInteger &other)
{
    bool flag = false;
    for (int i = 39; i >= 0; i--)
    {
        if (other.integer[i] != 0)
            flag = true;
        if (flag == true)
            output << other.integer[i];
    }
    return output << endl;
}