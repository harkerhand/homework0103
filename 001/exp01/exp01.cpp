#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex c1(1, 7), c2(9, 2), c3(10, 1), c4(11, 5);
    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << c3 << " - " << c4 << " = " << c3 - c4 << endl;
}