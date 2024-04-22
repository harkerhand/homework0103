#include <iostream>
#include <fstream>
#include <vector>
#include "Shape.h"
#include "shapes.h"
using namespace std;

int main()
{
    ofstream fout("output.txt", ios::trunc | ios::out);
    vector<Shape *> shapes;
    shapes.push_back(new Circle({1, 2}, 3));
    shapes.push_back(new Triangle({3, 3}, {0, 0}, {3, 0}));
    shapes.push_back(new Rectangle({2, 1}, 4, 3));
    shapes.push_back(new Square({3, 3}, 4));
    shapes.push_back(new Sphere({1, 1, 1}, 2));
    shapes.push_back(new Cylinder({0, 0, 0}, 3, 4));
    for (auto s : shapes)
    {
        s->print(fout);
        s->print();
    }
}