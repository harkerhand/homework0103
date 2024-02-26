#include <iostream>
#include "HugeInteger.h"
using namespace std;
int main()
{
    HugeInteger n1(7654321), n2("7891234"), n3(0);
    cout << "7654321 + 7891234 = ";
    n1.add(n2).output();
    cout << endl;

    // 重载更好用
    cout << "7891234 - 5 = " << n2.subtract(5) << endl;

    cout << "7654321 is " << (n1.isEqualTo(n1) ? "equal to " : "not equal to ") << "7654321\n\n";
    cout << "7654321 is " << (n1.isEqualTo(n2) ? "equal to " : "not equal to ") << "7891234\n\n";
    cout << "7891234 is " << (n2.isGreaterThan(n1) ? "greater than " : "not greater than ") << "7654321\n\n";
    cout << "5 is " << (HugeInteger(5).isLessThan(n2) ? "less than " : "not less than ") << "7891234\n\n";
    cout << "5 is " << (HugeInteger(5).isLessThanOrEqualTo(5) ? "less than or equal to " : "not less than or equal to ") << "5\n\n";
    cout << "0 is " << (HugeInteger(0).isGreaterThanOrEqualTo(0) ? "greater than or equal to " : "not greater than or equal to ") << "0\n\n";

    if (n3.isZero())
        cout << "n3 contains value 0\n";
    return 0;
}