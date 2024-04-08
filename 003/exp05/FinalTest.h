#pragma once

#include "Date.h"
#include <iostream>
class FinalTest
{
    friend std::ostream &operator<<(std::ostream &out, const FinalTest &in)
    {
        out << "Title: " << in.name << "\nTest Date: " << in.date << "\n";
        return out;
    }

private:
    std::string name;
    Date date;

public:
    FinalTest(std::string, Date);
    FinalTest(std::string);
    void print() const
    {
        std::cout << *this;
    }
    void setDate(Date d)
    {
        date = d;
    }
};

FinalTest::FinalTest(std::string n, Date d)
    : name(n), date(d)
{
}
FinalTest::FinalTest(std::string n)
    : name(n), date(Date())
{
}
