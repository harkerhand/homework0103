#ifndef HUGEINTERGER_H
#define HUGEINTERGER_H

#include <iostream>

class HugeInteger
{

public:
    HugeInteger(int = 0);
    HugeInteger(const char *);
    HugeInteger add(const HugeInteger &) const;
    HugeInteger add(const int) const;
    HugeInteger add(const char *) const;

    HugeInteger subtract(const HugeInteger &) const;
    HugeInteger subtract(const int) const;
    HugeInteger subtract(const char *) const;

    bool isEqualTo(const HugeInteger &) const;
    bool isNotEqualTo(const HugeInteger &) const;
    bool isGreaterThan(const HugeInteger &) const;
    bool isLessThan(const HugeInteger &) const;
    bool isGreaterThanOrEqualTo(const HugeInteger &) const;
    bool isLessThanOrEqualTo(const HugeInteger &) const;
    bool isZero() const;
    void input(const char *);
    void output() const;

    friend std::ostream &operator<<(std::ostream &, const HugeInteger &);

private:
    int integer[40] = {0};
};

#endif