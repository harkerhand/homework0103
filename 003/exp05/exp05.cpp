#include "Date.h"
#include "FinalTest.h"
#include <iostream>

int main()
{
    FinalTest item1("C++ Test", Date(2014, 6, 2));
    item1.print();
    FinalTest item2("Java");
    item2.print();
    item2.setDate(Date(2014, 6, 10));
    item2.print();
}