/*
 * @Date: 2024-02-19 14:29:48
 * @LastEditors: harkerhand harkerhand@outlook.com
 * @LastEditTime: 2024-02-19 14:50:29
 * @FilePath: \homework2\001\exp01\exp01.cpp
 */
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex c1(1.0, 2.0), c2(3.0, 4.0);
    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
}