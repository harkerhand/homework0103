#include "Shape.h"
#include <array>
#include <iostream>
using namespace std;
class Circle : public Shape
{
public:
    Circle()
    {
        radius = 0;
        center = {0, 0};
        left = {0, 0};
        right = {0, 0};
        id = "Circle";
    }
    Circle(array<double, 2> c, double r)
        : center(c), radius(r)
    {
        left = {center[0] - radius, center[1]};
        right = {center[0] + radius, center[1]};
        id = "Circle";
    }
    double area() const
    {
        return 3.14159 * radius * radius;
    }
    void print()
    {
        cout << "Id: " << id << "\n";
        cout << "Center: (" << center[0] << ", " << center[1] << ")\n";
        cout << "Left: (" << left[0] << ", " << left[1] << ")\n";
        cout << "Right: (" << right[0] << ", " << right[1] << ")\n";
        cout << "Radius: " << radius << "\n";
        cout << "Area: " << area() << "\n";
        cout << "\n";
    }
    ~Circle()
    {
    }

private:
    array<double, 2> center;
    array<double, 2> left;
    array<double, 2> right;
    double radius;
};

class Triangle : public Shape
{
public:
    Triangle()
    {
        id = "Triangle";
        a = {0, 0};
        b = {0, 0};
        c = {0, 0};
    }
    Triangle(array<double, 2> a, array<double, 2> b, array<double, 2> c)
        : a(a), b(b), c(c)
    {
        id = "Triangle";
    }

    double area() const
    {
        return abs((a[0] * (b[1] - c[1])) + (b[0] * (c[1] - a[1])) + (c[0] * (a[1] - b[1]))) / 2;
    }

    void print() const
    {
        cout << "Id: " << id << "\n";
        cout << "A: (" << a[0] << ", " << a[1] << ")\n";
        cout << "B: (" << b[0] << ", " << b[1] << ")\n";
        cout << "C: (" << c[0] << ", " << c[1] << ")\n";
        cout << "Area: " << area() << "\n";
        cout << "\n";
    }

private:
    array<double, 2> a;
    array<double, 2> b;
    array<double, 2> c;
};

class Rectangle : public Shape
{
public:
    Rectangle()
    {
        id = "Rectangle";
        leftUp = {0, 0};
        rightDown = {0, 0};
        length = 0;
        width = 0;
    }
    Rectangle(array<double, 2> l, double leng, double wid)
        : leftUp(l), length(leng), width(wid)
    {
        id = "Rectangle";
        rightDown = {leftUp[0] + length, leftUp[1] + width};
    }
    Rectangle(array<double, 2> l, array<double, 2> r)
        : leftUp(l), rightDown(r)
    {
        id = "Rectangle";
    }
    ~Rectangle()
    {
    }
    double area() const
    {
        return (rightDown[0] - leftUp[0]) * (rightDown[1] - leftUp[1]);
    }

    void print() const
    {
        cout << "Id: " << id << "\n";
        cout << "Left up: (" << leftUp[0] << ", " << leftUp[1] << ")\n";
        cout << "Right down: (" << rightDown[0] << ", " << rightDown[1] << ")\n";
        cout << "Area: " << area() << "\n";
        cout << "\n";
    }

protected:
    array<double, 2> leftUp;
    array<double, 2> rightDown;
    double length;
    double width;
};

class Square : public Rectangle
{
public:
    Square()
    {
        id = "Square";
        leftUp = {0, 0};
        rightDown = {0, 0};
        length = 0;
        width = 0;
    }
    Square(array<double, 2> l, double leng)
    {
        id = "Square";
        leftUp = l;
        length = leng;
        width = leng;
        rightDown = {leftUp[0] + length, leftUp[1] + width};
    }
    ~Square()
    {
    }
    double area() const
    {
        return length * length;
    }

    Circle incircle()
    {
        return Circle({leftUp[0] + length / 2, leftUp[1] + length / 2}, length / 2);
    }
    void print() const
    {
        cout << "Id: " << id << "\n";
        cout << "Left up: (" << leftUp[0] << ", " << leftUp[1] << ")\n";
        cout << "Length: " << length << "\n";
        cout << "Area: " << area() << "\n";
        cout << "\n";
    }
};
