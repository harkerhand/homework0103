#include <iostream>
using std::cout;
using std::endl;
#include "RationalNumber.h"
int main()
{
    RationalNumber c(7, 3), d(3, 9), x;
    c.printRational();
    cout << " + ";
    d.printRational();
    cout << " = ";
    x = c + d;
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " - ";
    d.printRational();
    cout << " = ";
    x = c - d;
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " * ";
    d.printRational();
    cout << " = ";
    x = c * d;
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " / ";
    d.printRational();
    cout << " = ";
    x = c / d;
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " is:\n";
    cout << ((c > d) ? " > " : " <= ");
    d.printRational();
    cout << " according to the overloaded > operator\n";
    cout << ((c < d) ? " < " : " >= ");
    d.printRational();
    cout << " according to the overloaded < operator\n";
    cout << ((c >= d) ? " >= " : " < ");
    d.printRational();
    cout << " according to the overloaded >= operator\n";
    cout << ((c <= d) ? " <= " : " > ");
    d.printRational();
    cout << " according to the overloaded <= operator\n";
    cout << ((c == d) ? " == " : " != ");
    d.printRational();
    cout << " according to the overloaded == operator\n";
    cout << ((c != d) ? " != " : " == ");
    d.printRational();
    cout << " according to the overloaded != operator" << endl;
    return 0;
}