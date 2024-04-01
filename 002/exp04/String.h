#pragma once

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class String
{
    friend ostream &operator<<(ostream &os, const String &str);

public:
    String(const char *s = "");
    String(const String &str);
    ~String();
    const String &operator=(const String &str);
    String operator+(const String &str) const;

private:
    char *sPtr;
    int length;
};