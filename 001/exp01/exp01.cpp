#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex c1(1.0, 2.0), c2(3.0, 4.0);
    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
}