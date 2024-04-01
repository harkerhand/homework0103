#pragma once

#include "MyBase1.h"

class MyDerived1 : public MyBase1
{
public:
    MyDerived1()
    {
        cout << "MyDerived1 constructor" << endl;
    }

    ~MyDerived1()
    {
        cout << "MyDerived1 destructor" << endl;
    }
};