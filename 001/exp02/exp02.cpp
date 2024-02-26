#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

int main()
{

    Time t1(23, 59, 57);
    Time t2 = t1;

    cout << "使用成员函数 : " << endl;
    for (int i = 0; i < 15; i++)
    {
        t1.printStandard();
        t1.tick_InsideTime();
        cout << endl;
    }

    cout << "---------------------------------------" << endl;

    cout << "使用友元函数 : " << endl;
    for (int i = 0; i < 15; i++)
    {
        t2.printStandard();
        tick_Friend(t2);
        cout << endl;
    }
}