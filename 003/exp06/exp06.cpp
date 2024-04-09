#include "Shape.h"
#include <iostream>
#include <fstream>
#include "shapes.h"

using namespace std;
int main()
{
    Circle c1({1, 2}, 3);
    Triangle t1({3, 3}, {0, 0}, {3, 0});
    Rectangle r1({2, 1}, 4, 3);
    Square s1({3, 3}, 4);
    Circle c2 = s1.incircle();

    // 实现了文件和屏幕输出
    ofstream fout("output.txt", ios::trunc | ios::out);
    if (!fout.is_open())
        cout << "error" << endl;
    else
    {
        c1.print(fout);
        t1.print(fout);
        r1.print(fout);
        s1.print(fout);
        c2.print(fout);
        fout.close();
    }
    c1.print();
    t1.print();
    r1.print();
    s1.print();
    c2.print();
}