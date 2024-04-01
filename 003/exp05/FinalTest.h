#pragma once

#include "Date.h"
#include <iostream>
using namespace std;
class FinalTest
{
    friend ostream &operator<<(ostream &cout, const FinalTest &in)
    {
        cout << "Title: " << in.name << "\nTest Date: " << in.date << "\n";
        return cout;
    }

private:
    string name;
    Date date;

public:
    FinalTest(string, Date);
    FinalTest(string);
    void print() const
    {
        cout << *this;
    }
    void setDate(Date d)
    {
        date = d;
    }
};

FinalTest::FinalTest(string n, Date d)
    : name(n), date(d)
{
}
FinalTest::FinalTest(string n)
    : name(n), date(Date())
{
}
