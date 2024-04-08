#pragma once
#include <string>
using namespace std;
class Shape
{
public:
    Shape(const std::string idIN = "Shape") : id(idIN) {}
    ~Shape()
    {
    }
    string id;
};
