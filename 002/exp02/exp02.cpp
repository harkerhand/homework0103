#include <iostream>
#include "HugeInt.h"
using namespace std;

int main()
{
    HugeInt n1(7654321), n2(7891234), n3("99999999999999999999999999999"), n4(1), n5(12341234), n6(7888), result("0");
    cout << "n1 is " << n1 << endl;
    cout << "n2 is " << n2 << endl;
    cout << "n3 is " << n3 << endl;
    cout << "n4 is " << n4 << endl;
    cout << "n5 is " << n5 << endl;
    cout << "n6 is " << n6 << endl;
    cout << "result is " << result << endl
         << endl;
    cout << "n1 is " << (n1 == n2 ? "" : "not ") << "equal to n2 " << endl;
    cout << "n1 is " << (n1 < n2 ? "" : "not ") << "less than n2 " << endl;
    cout << "n1 is " << (n1 <= n2 ? "" : "not ") << "less than or equal to n2 " << endl;
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl
         << endl;
    cout << n3 << " + " << n4 << " = " << n3 + n4 << endl
         << endl;
    cout << n1 << " + " << 9 << " = " << n1 + 9 << endl;
    cout << n2 << " + " << 10000 << " = " << n2 + 10000 << endl;
    cout << n5 << " * " << n6 << " = " << n5 * n6 << endl;
    cout << n5 << " - " << n6 << " = " << n5 - n6 << endl;
    cout << n5 << " / " << n6 << " = " << n5 / n6 << endl;
}