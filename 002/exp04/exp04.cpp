#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    String s1, s2("the date is");
    String s3 = " august 1, 1993";
    cout << "s1 = s2 + s3\n";
    s1 = s2 + s3;
    cout << "\"" << s1 << "\" = \"" << s2 << "\" + \"" << s3 << "\"\n";
    return 0;
}