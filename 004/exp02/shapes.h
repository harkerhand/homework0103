#include "Shape.h"
#include <tuple>
#include <iostream>
using std::array;
using std::cout;
using std::endl;
using std::get;
using std::make_pair;
using std::make_tuple;
using std::pair;
using std::string;
using std::tuple;

constexpr double M_PI = 3.14159265358979323846;

class TwoDimensionalShape : public Shape
{
public:
    TwoDimensionalShape(std::string id = "TwoDimensionalShape", pair<double, double> c = make_pair(0, 0)) : Shape(id), center(c) {}
    virtual ~TwoDimensionalShape() {}
    virtual double getArea() const = 0;
    virtual void print(std::ostream &out = cout) const = 0;

protected:
    pair<double, double> center;
};

class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape(std::string id = "ThreeDimensinalShape", tuple<double, double, double> c = make_tuple(0, 0, 0)) : Shape(id), center(c) {}
    virtual ~ThreeDimensionalShape() {}
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
    virtual void print(std::ostream &out = cout) const = 0;

protected:
    tuple<double, double, double> center;
};

class Circle : public TwoDimensionalShape
{
public:
    Circle() : TwoDimensionalShape("Circle", make_pair(0, 0)), radius(0), left({0, 0}), right({0, 0}) {}
    Circle(pair<double, double> c, double r) : TwoDimensionalShape("Circle", c), radius(r)
    {
        left = {center.first - radius, center.second};
        right = {center.first + radius, center.second};
    }
    virtual double getArea() const override
    {
        return M_PI * radius * radius;
    }
    virtual void print(std::ostream &out = cout) const override
    {
        out << "Id: " << id << "\n";
        out << "Center: (" << center.first << ", " << center.second << ")\n";
        out << "Left: (" << left.first << ", " << left.second << ")\n";
        out << "Right: (" << right.first << ", " << right.second << ")\n";
        out << "Radius: " << radius << "\n";
        out << "Area: " << getArea() << "\n";
        out << "\n";
    }
    ~Circle() {}

private:
    pair<double, double> left;
    pair<double, double> right;
    double radius;
};

class Triangle : public TwoDimensionalShape
{
public:
    Triangle() : TwoDimensionalShape("Triangle", make_pair(0, 0)), a({0, 0}), b({0, 0}), c({0, 0}) {}
    Triangle(pair<double, double> a, pair<double, double> b, pair<double, double> c)
        : TwoDimensionalShape("Triangle", make_pair((a.first + b.first + c.first) / 3, (a.second + b.second + c.second) / 3)), a(a), b(b), c(c) {}
    ~Triangle() {}
    double getArea() const override
    {
        return std::abs((a.first * (b.second - c.second)) + (b.first * (c.second - a.second)) + (c.first * (a.second - b.second))) / 2;
    }

    void print(std::ostream &out = cout) const override
    {
        out << "Id: " << id << "\n";
        out << "Center: (" << center.first << ", " << center.second << ")\n";
        out << "A: (" << a.first << ", " << a.second << ")\n";
        out << "B: (" << b.first << ", " << b.second << ")\n";
        out << "C: (" << c.first << ", " << c.second << ")\n";
        out << "Area: " << getArea() << "\n";
        out << "\n";
    }

private:
    pair<double, double> a;
    pair<double, double> b;
    pair<double, double> c;
};

class Rectangle : public TwoDimensionalShape
{
public:
    Rectangle(const string &idIN = "Rectangle") : TwoDimensionalShape(id, make_pair(0, 0)), leftUp({0, 0}), rightDown({0, 0}), length(0), width(0) {}
    Rectangle(pair<double, double> l, double leng, double wid, std::string id = "Rectangle") : TwoDimensionalShape(id, make_pair((l.first + l.first + leng) / 2, (l.second + l.second - wid) / 2)), leftUp(l), length(leng), width(wid)
    {
        rightDown = {leftUp.first + length, leftUp.second - width};
    }
    Rectangle(pair<double, double> l, pair<double, double> r, std::string id = "Rectangle") : TwoDimensionalShape(id, make_pair((l.first + r.first) / 2, (l.second + r.second) / 2)), leftUp(l), rightDown(r)
    {
        length = std::abs(leftUp.first - rightDown.first);
        width = std::abs(rightDown.second - leftUp.second);
    }
    ~Rectangle() {}
    double getArea() const override
    {
        return std::abs((rightDown.first - leftUp.first) * (leftUp.second - rightDown.second));
    }

    void print(std::ostream &out = cout) const override
    {
        out << "Id: " << id << "\n";
        out << "Center: (" << center.first << ", " << center.second << ")\n";
        out << "Left up: (" << leftUp.first << ", " << leftUp.second << ")\n";
        out << "Right down: (" << rightDown.first << ", " << rightDown.second << ")\n";
        out << "Area: " << getArea() << "\n";
        out << "\n";
    }

protected:
    pair<double, double> leftUp;
    pair<double, double> rightDown;
    double length;
    double width;
};

class Square : public Rectangle
{
public:
    Square() : Rectangle("Square") {}
    Square(pair<double, double> l, double leng) : Rectangle(l, leng, leng, "Square") {}
    Square(pair<double, double> l, pair<double, double> r) : Rectangle(l, r, "Square") {}
    ~Square() {}
    double getArea() const override
    {
        return length * length;
    }

    Circle incircle() const
    {
        return Circle(make_pair(leftUp.first + length / 2, leftUp.second - length / 2), length / 2);
    }
    void print(std::ostream &out = cout) const override
    {
        out << "Id: " << id << "\n";
        out << "Left up: (" << leftUp.first << ", " << leftUp.second << ")\n";
        out << "Length: " << length << "\n";
        out << "Area: " << getArea() << "\n";
        out << "Incircle: \n";
        incircle().print(out);
    }
};

class Sphere : public ThreeDimensionalShape
{
public:
    Sphere() : ThreeDimensionalShape("Sphere", make_tuple(0, 0, 0)) {}
    Sphere(tuple<double, double, double> c, double r) : ThreeDimensionalShape("Sphere", c), radius(r) {}
    ~Sphere() {}

    virtual double getArea() const override
    {
        return 4 * M_PI * radius * radius;
    }
    virtual double getVolume() const override
    {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }

    virtual void print(std::ostream &out = cout) const override
    {
        out << "Id: " << id << "\n";
        out << "Center: (" << get<0>(center) << ", " << get<1>(center) << ", " << get<2>(center) << ")\n";
        out << "Radius: " << radius << "\n";
        out << "Area: " << getArea() << "\n";
        out << "Volume: " << getVolume() << "\n";
        out << "\n";
    }

private:
    double radius;
};

class Cylinder : public ThreeDimensionalShape
{

public:
    Cylinder() : ThreeDimensionalShape("Cylinder", make_tuple(0, 0, 0)) {}
    Cylinder(tuple<double, double, double> c, double r, double h) : ThreeDimensionalShape("Cylinder", c), radius(r), height(h), topCenter(make_tuple(get<0>(c), get<1>(c), get<2>(c) + h / 2)), downCenter(make_tuple(get<0>(c), get<1>(c), get<2>(c) - h / 2)) {}
    ~Cylinder() {}

    virtual double getArea() const override
    {
        return 2 * M_PI * radius * height;
    }
    virtual double getVolume() const override
    {
        return M_PI * radius * radius * height;
    }

    void print(std::ostream &out = cout) const override
    {
        out << "Id: " << id << "\n";
        out << "Center: (" << get<0>(center) << ", " << get<1>(center) << ", " << get<2>(center) << ")\n";
        out << "Top center: (" << get<0>(topCenter) << ", " << get<1>(topCenter) << ", " << get<2>(topCenter) << ")\n";
        out << "Down center: (" << get<0>(downCenter) << ", " << get<1>(downCenter) << ", " << get<2>(downCenter) << ")\n";
        out << "Radius: " << radius << "\n";
        out << "Height: " << height << "\n";
        out << "Area: " << getArea() << "\n";
        out << "Volume: " << getVolume() << "\n";
        out << "\n";
    }

private:
    double radius;
    double height;
    tuple<double, double, double> topCenter;
    tuple<double, double, double> downCenter;
};