#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
using std::ostream;
class HugeInt
{
    friend ostream &operator<<(ostream &, const HugeInt &);

private:
    short integer[30];
    HugeInt HugeIntMutiANumber(const HugeInt &, const short &) const;

public:
    HugeInt(long = 0);
    HugeInt(const char *);
    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const char *) const;
    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;
    HugeInt operator-(const HugeInt &) const;
    HugeInt operator*(const HugeInt &) const;
    HugeInt operator/(const HugeInt &) const;
    int getLength() const;
};

#endif