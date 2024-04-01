#pragma once
#include "MyDerived1.h"

class MyDerived11 : public MyDerived1
{
public:
    MyDerived11()
    {
        cout << "MyDerived11" << endl;
    }
    ~MyDerived11()
    {
        cout << "~MyDerived11" << endl;
    }
};