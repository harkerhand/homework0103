#pragma once
class Shape
{
public:
    Shape(const std::string idIN = "Shape") : id(idIN) {}
    virtual ~Shape()
    {
    }
    virtual double getArea() const = 0;
    virtual void print(std::ostream &out) const = 0;

protected:
    std::string id;
};
