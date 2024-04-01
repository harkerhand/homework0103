#pragma once
#include <iostream>
using namespace std;
class MyBase1
{
public:
    MyBase1()
    {
        cout << "MyBase1 constructor" << endl;
    }
    ~MyBase1()
    {
        cout << "MyBase1 destructor" << endl;
    }
};