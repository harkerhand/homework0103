#include "HugeInt.h"
#include <iostream>
using std::ostream;

HugeInt::HugeInt(long temp)
{
    for (size_t i = 0; i < 30; i++)
    {
        integer[i] = temp % 10;
        temp /= 10;
    }
}
HugeInt::HugeInt(const char *s)
{
    size_t i = 0;
    for (; i < 30; i++)
    {
        if (s[i] != '\0')
        {
            if (s[i] < '0' || s[i] > '9')
                throw "Invalid digit";
            else
                integer[i] = s[i] - '0';
        }
        else
            break;
    }
    for (; i < 30; i++)
        integer[i] = 0;
}
HugeInt HugeInt::operator+(const HugeInt &other) const
{
    bool carry = 0;
    HugeInt temp;
    for (size_t i = 0; i < 30; i++)
    {
        short tempShort = this->integer[i] + other.integer[i] + carry;
        temp.integer[i] = tempShort % 10;
        carry = tempShort / 10;
    }
    return temp;
}
HugeInt HugeInt::operator+(int other) const
{
    return *this + HugeInt(other);
}
HugeInt HugeInt::operator+(const char *other) const
{
    return *this + HugeInt(other);
}
bool HugeInt::operator==(const HugeInt &other) const
{
    for (size_t i = 0; i < 30; i++)
    {
        if (this->integer[i] != other.integer[i])
            return false;
    }
    return true;
}
bool HugeInt::operator!=(const HugeInt &other) const
{
    return !(*this == other);
}
bool HugeInt::operator<(const HugeInt &other) const
{
    for (size_t i = 29; i >= 0; i--)
    {
        if (this->integer[i] < other.integer[i])
            return true;
        else if (this->integer[i] > other.integer[i])
            return false;
    }
    return false;
}
bool HugeInt::operator<=(const HugeInt &other) const
{
    return (*this < other) || (*this == other);
}
bool HugeInt::operator>(const HugeInt &other) const
{
    return !(*this <= other);
}
bool HugeInt::operator>=(const HugeInt &other) const
{
    return !(*this < other);
}
HugeInt HugeInt::operator-(const HugeInt &other) const
{
    bool negative = 0;
    HugeInt temp;
    for (size_t i = 0; i < 30; i++)
    {
        short tempShort = this->integer[i] - other.integer[i] - negative;
        temp.integer[i] = (tempShort + 10) % 10;
        negative = tempShort < 0;
    }
    return temp;
}
HugeInt HugeInt::operator*(const HugeInt &other) const
{
    HugeInt temp;
    for (size_t i = 0; i < 30; i++)
    {
        HugeInt tempHugeInt = HugeIntMutiANumber(other, this->integer[i]);
        for (size_t j = 0; j < i; j++)
        {
            for (size_t k = 30; k > 0; k--)
                tempHugeInt.integer[k] = tempHugeInt.integer[k - 1];
            tempHugeInt.integer[0] = 0;
        }
        temp = temp + tempHugeInt;
    }
    return temp;
}
HugeInt HugeInt::operator/(const HugeInt &other) const
{
    if (other == "0")
        throw "Error: division by zero";
    for (HugeInt i(1); 1; i = i + 1)
    {
        if (*this < other * i)
            return HugeInt(i - 1);
    }
    return "0";
}
int HugeInt::getLength() const
{
    for (size_t i = 0; i < 30; i++)
    {
        if (this->integer[i] == 0)
        {
            return i;
        }
    }
    return 30;
}

ostream &operator<<(ostream &output, const HugeInt &hugeInt)
{
    for (size_t i = 29; i > 0; i--)
    {
        if (hugeInt.integer[i] != 0)
        {
            for (; i > 0; i--)
                output << hugeInt.integer[i];
            break;
        }
    }
    output << hugeInt.integer[0];
    return output;
}

HugeInt HugeInt::HugeIntMutiANumber(const HugeInt &other, const short &a) const
{
    HugeInt temp;
    short carry;
    for (size_t i = 0; i < 30; i++)
    {
        short tempShort = other.integer[i] * a + carry;
        temp.integer[i] = tempShort % 10;
        carry = tempShort / 10;
    }
    return temp;
}