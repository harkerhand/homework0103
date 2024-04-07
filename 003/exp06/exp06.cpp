#include "Shape.h"
#include <iostream>
#include "shapes.h"

using namespace std;
int main()
{
    Circle c1({1, 2}, 3);
    Triangle t1({3, 3}, {0, 0}, {3, 0});
    Rectangle r1({2, 1}, 4, 3);
    Square s1({3, 3}, 4);
    Circle c2 = s1.incircle();

    c1.print();
    t1.print();
    r1.print();
    s1.print();
    c2.print();
    // test
}