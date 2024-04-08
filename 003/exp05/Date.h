#pragma once
#include <iostream>
class Date
{
    friend std::ostream &operator<<(std::ostream &cout, const Date &in)
    {
        return cout << "Date: " << in.year << "-" << in.month << "-" << in.day;
    }

private:
    int year;
    int month;
    int day;

public:
    Date(int = 2014, int = 1, int = 1);
};

Date::Date(int y, int m, int d)
    : year(y), month(m), day(d)
{
}
