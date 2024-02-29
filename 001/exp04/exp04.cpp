#include <iostream>
#include <stdexcept>
#include "SimpleCalculator.h"
using namespace std;

int main()
{
    SimpleCalculator sc;
    double a = 10, b = 20;
    cout << "The value of a is: " << a << endl;
    cout << "The value of b is: " << b << endl;
    cout << "\nAdding a and b yields " << sc.add(a, b) << endl;
    cout << "Subtracting b from a yields " << sc.subtract(a, b) << endl;
    cout << "Multiplying a by b yields " << sc.multiply(a, b) << endl;
    cout << "Dividing a by b yields " << sc.divide(a, b) << endl;

    // 测试除以0的情况
    /* try
    {
        double ans = sc.divide(a, 0);
        cout << "Dividing a by 0 yields " << ans << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl; // "Division by zero condition!"
    } */

    return 0;
}