#include "Shape.h"
#include <array>
#include <iostream>
#define M_PI 3.14159265358979323846
using std::array;
using std::cout;
using std::endl;
class Circle : private Shape
{
public:
    Circle() : Shape("Circle"), radius(0), center({0, 0}), left({0, 0}), right({0, 0}) {}
    Circle(array<double, 2> c, double r) : Shape("Circle"), center(c), radius(r)
    {
        left = {center[0] - radius, center[1]};
        right = {center[0] + radius, center[1]};
    }
    double area() const
    {
        return M_PI * radius * radius;
    }
    void print(std::ostream &out = cout) const
    {
        out << "Id: " << id << "\n";
        out << "Center: (" << center[0] << ", " << center[1] << ")\n";
        out << "Left: (" << left[0] << ", " << left[1] << ")\n";
        out << "Right: (" << right[0] << ", " << right[1] << ")\n";
        out << "Radius: " << radius << "\n";
        out << "Area: " << area() << "\n";
        out << "\n";
    }
    ~Circle() {}

private:
    array<double, 2> center;
    array<double, 2> left;
    array<double, 2> right;
    double radius;
};

class Triangle : private Shape
{
public:
    Triangle() : Shape("Triangle"), a({0, 0}), b({0, 0}), c({0, 0}) {}
    Triangle(array<double, 2> a, array<double, 2> b, array<double, 2> c)
        : Shape("Triangle"), a(a), b(b), c(c) {}
    ~Triangle() {}
    double area() const
    {
        return std::abs((a[0] * (b[1] - c[1])) + (b[0] * (c[1] - a[1])) + (c[0] * (a[1] - b[1]))) / 2;
    }

    void print(std::ostream &out = cout) const
    {
        out << "Id: " << id << "\n";
        out << "A: (" << a[0] << ", " << a[1] << ")\n";
        out << "B: (" << b[0] << ", " << b[1] << ")\n";
        out << "C: (" << c[0] << ", " << c[1] << ")\n";
        out << "Area: " << area() << "\n";
        out << "\n";
    }

private:
    array<double, 2> a;
    array<double, 2> b;
    array<double, 2> c;
};

class Rectangle : protected Shape
{
public:
    Rectangle(std::string id = "Rectangle") : Shape(id), leftUp({0, 0}), rightDown({0, 0}), length(0), width(0) {}
    Rectangle(array<double, 2> l, double leng, double wid, std::string id = "Rectangle") : Shape(id), leftUp(l), length(leng), width(wid)
    {
        rightDown = {leftUp[0] + length, leftUp[1] - width};
    }
    Rectangle(array<double, 2> l, array<double, 2> r, std::string id = "Rectangle") : Shape(id), leftUp(l), rightDown(r)
    {
        length = std::abs(leftUp[0] - rightDown[0]);
        width = std::abs(rightDown[1] - leftUp[1]);
    }
    ~Rectangle() {}
    double area() const
    {
        return (rightDown[0] - leftUp[0]) * (leftUp[1] - rightDown[1]);
    }

    void print(std::ostream &out = cout) const
    {
        out << "Id: " << id << "\n";
        out << "Left up: (" << leftUp[0] << ", " << leftUp[1] << ")\n";
        out << "Right down: (" << rightDown[0] << ", " << rightDown[1] << ")\n";
        out << "Area: " << area() << "\n";
        out << "\n";
    }

protected:
    array<double, 2> leftUp;
    array<double, 2> rightDown;
    double length;
    double width;
};

class Square : private Rectangle
{
public:
    Square() : Rectangle("Square") {}
    Square(array<double, 2> l, double leng) : Rectangle(l, leng, leng, "Square") {}
    Square(array<double, 2> l, array<double, 2> r) : Rectangle(l, r, "Square") {}
    ~Square() {}
    double area() const
    {
        return length * length;
    }

    Circle incircle() const
    {
        return Circle({leftUp[0] + length / 2, leftUp[1] + length / 2}, length / 2);
    }
    void print(std::ostream &out = cout) const
    {
        out << "Id: " << id << "\n";
        out << "Left up: (" << leftUp[0] << ", " << leftUp[1] << ")\n";
        out << "Length: " << length << "\n";
        out << "Area: " << area() << "\n";
        out << "Incircle: \n";
        incircle().print(out);
    }
};
